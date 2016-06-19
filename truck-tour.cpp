#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    truck tour implementation on hackerrank
*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long N;
    cin >> N;
    
    
    long arr[N][2];
    long memo[N+1];
    long globalMin = -1;
    long currPetrol = 0;
    int currDistance = 0;
    for(long i = 0; i < N; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
        //cout <<  "petrol: " <<arr[i][0] <<" dist: " << arr[i][1] <<endl;
    }
    bool breaker = true;
    while(breaker){
        long travelled = 0;
        
        for(long i = 0; i < N; i++){//staritng point loop
            currPetrol = arr[i][0];
            
            long destStep = (i)%(N-1);
            //printf("INDEX %d\n",i);
            for(long j = 0; j < N; j++){//looping through the circle for each starting point?
                //indexing at 0?  need to make sure the modulo 
                //used for the index of the next destination is correct hmmmm
                
                //printf("destStep %d\n",destStep);
                if(destStep == i)
                    currPetrol -= arr[destStep][1];// + petrol - distance?
                else
                    currPetrol += arr[destStep][0] - arr[destStep][1];// + petrol - distance?
                destStep = (destStep+1)%(N-1);
                //printf("IN LOOP index[%d] currPetrol %d \n",destStep,currPetrol);
                
                if(currPetrol < 0)//quit whenever petrol is neg
                    break;
            }
            if(currPetrol >= 0){
                //printf("Answer:: currPetrol %d index %d\n",currPetrol,i);
                globalMin = i;
                breaker = false;
            }
               
             //printf("INDEX END %d\n",i);
        }
        breaker = false;
    }
    printf("%ld\n", globalMin);
    return 0;
}
