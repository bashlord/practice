#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack> 
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    int arr[N][2];
    
    for(int i = 0; i < N; i++){//populate arr with days at index 0, 1 with pesticide
        arr[i][0] = i;
        cin >> arr[i][1];
    }
    vector<vector<int>> mystack;
    int daysMax = 0;
    
    for(int i  = 0; i < N; i++){//for each plant
        int days = 0;
        
        while(!mystack.empty() && arr[i][1] <= mystack.at(mystack.size()-1)[1]){
            //while stack is not empty and the current pesticide is <= top of the stack pesticide
                int b = (mystack.back()).at(0);
                days = max(days, b);
                mystack.pop_back();
        }
        
        if(mystack.empty()){//if it is empty, 0 days for plants to die
            days = 0;
        }else{
            days++;//else, increment
        }
        
        daysMax = max(daysMax,days);//choose between the global max days so far, and the current checker
        vector<int> plant;
        plant.push_back(days);//plant's day
        plant.push_back(arr[i][1]);//plant's pesticide
        
        mystack.push_back(plant);//push it back onto the stack
        
    }
    printf("%d\n", daysMax);
    
    
    return 0;
}
