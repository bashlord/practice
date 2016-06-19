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
    
    for(int i = 0; i < N; i++){
        arr[i][0] = i;
        cin >> arr[i][1];
    }
    vector<vector<int>> mystack;
    int daysMax = 0;
    
    for(int i  = 0; i < N; i++){
        int days = 0;
        
        while(!mystack.empty() && arr[i][1] <= mystack.at(mystack.size()-1)[1]){
                int b = (mystack.back()).at(0);
                
                days = max(days, b);
                mystack.pop_back();
            
            
        }
        
        if(mystack.empty()){
            days = 0;
        }else{
            days++;
        }
        
        daysMax = max(daysMax,days);
        vector<int> plant;
        plant.push_back(days);
        plant.push_back(arr[i][1]);
        
        mystack.push_back(plant);
        
    }
    printf("%d\n", daysMax);
    
    
    return 0;
}

