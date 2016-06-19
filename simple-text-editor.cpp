#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


int main() {
    int N;
    int a;
        string s;
    cin >> N;
    vector<pair<int,string>> arr;
    string output = "";
    int undoFlag = 0;
    
    string substr = "";
    int subint = -1;
    stack<pair<int,string>> mystack;
    for(int i = 0; i < N; i++){
        
        cin >> a;
        if(a != 4){
            cin >> s;
            arr.push_back(make_pair(a,s));
        }else{
            arr.push_back(make_pair(a,""));
        }
        
    }
    
    for(int i = 0; i < N; i++){
        a = arr[i].first;
        //cout << "======command: " << a << endl;
        if(a ==1 ){//append at end
            output.append(arr[i].second);
            subint = arr[i].second.length()-1;
            mystack.push(make_pair(2,to_string(subint)));
        }else if(a == 2){//delete last n 
            int ato = atoi(arr[i].second.c_str())-1;
            //cout << "ato " << ato << " len " << output.length()-1 << endl; 
            substr = output.substr((output.length()-1)-ato,output.length());
            output = output.substr(0,(output.length()-1)-ato);
            mystack.push(make_pair(1,substr));
        }else if(a == 3){//print kth 
            int index = atoi(arr[i].second.c_str())-1;
            printf("%c\n", output.at(index));
        }else if(a == 4 && i > 0 && !mystack.empty() ){
            //undo if last was not 4 and was 1 or 2
            //cout << "4" << endl;
            int cmd = mystack.top().first;
            string s;
            int is;
            if(cmd == 1){  
                 s = mystack.top().second;
               // cout << "4--1->"<<s << endl;
               
                output.append(s);
            }else{
                //cout << "4--2"<< endl;
                 is = atoi(mystack.top().second.c_str())+1;
                output = output.substr(0,output.length()-is);
            }
            mystack.pop();
            undoFlag = 0;
            
        }
        //cout << "---"<< output << endl;
    }
    return 0;
}

