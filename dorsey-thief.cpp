#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define INF (1<<30)
typedef long long int ll;
typedef struct Point Pt;
struct Point
{
    int v,wt;
    bool operator<(const Pt t)const
    {
        if(t.v<v)
            return 1;
        else
            return 0;
    }
}input[1000001];
vector<int> myvector[5001];     //max x is 5000
int size[5001];             //max x is 5000
ll dp[5001];                //max x is 5000
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int N,x,y,value;
    scanf("%d%d",&N,&x);
    for(int i=0;i<N;i++)    scanf("%d%d",&input[i].v,&input[i].wt);
    sort(input,input+N);        //sorting by decreasing value.
    memset(size,0,sizeof(size));

    for(int i=0;i<N;i++){
        y=input[i].wt;
        if(y>x) continue;
        else if(size[y]>x/y)    continue;           //stroing only the best x/y amounts for each y
        else{
            myvector[y].push_back(input[i].v);  
            size[y]++;
        }
    }

    //memset(dp,0,sizeof(dp));
    for(int i=1;i<=x;i++)   dp[i]=-(ll)1000000000*(ll)100000000;
    dp[0]=0;
    for(int i=1;i<=x;i++){
        while(!myvector[i].empty()){
            value=myvector[i].back();
            for(int j=x;j>=i;j--){
                if(dp[j-i]>=0){
                    cout << "for j-> " <<j <<endl;
                    cout << "dp[j]=max(dp[j],dp[j-i]+(ll)value)-> " <<dp[j] <<" " << dp[j-i]+(ll)value <<endl;
                    dp[j]=max(dp[j],dp[j-i]+(ll)value); 
                }
            }
            myvector[i].pop_back(); 
        }
    }
    if(dp[x]>=0)    printf("%lld\n",dp[x]);
    else    printf("Got caught!");
    for(int i = 0; i <= x; i++){
        cout << dp[i] << " ";
    }
    return 0;
}
