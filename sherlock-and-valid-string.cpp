#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[26];
int counts[26];
int main() {
    string word;
    cin >> word;
    int num = -1;
    int len = strlen(word.c_str());
    char arr[len];
    
    strcpy(arr, word.c_str());
    int chance = 0;
    for(int i = 0; i < len; i++){
        //cout << word[i] <<endl;
        counts[int(arr[i])-97]++;
    }
    for(int i = 0; i < 26; i++){
        //cout << word[i] <<endl;
        //cout << counts[i] << " ";
    }
    for(int i = 0; i < 26; i++){
        //cout << word[i] <<endl;
        //cout << counts[i] << " ";
        if(counts[i] != 0){
            if(num == -1){
                num = counts[i];
            }else{
                if(counts[i] != num ){
                    if(chance == 0){
                    //printf("counts[%d] != %d", counts[i],num);
                    //cout << "NO"<<endl;
                   // return 0;
                    chance++;
                }else{
                    //printf("counts[%d](%d) != %d chance %d\n", i,counts[i],num,chance);
                    cout << "NO"<<endl;
                    return 0;
                    }
                }
            }
        }
    }
    cout << "YES"<<endl;
    return 0;
}

