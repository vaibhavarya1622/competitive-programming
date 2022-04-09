#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int C[49][49];
int solve(){
    int dp[49];
    memset(dp,0,sizeof(dp));
    for(int e=1;e<49;++e){
        for(int s=0;s<e;++s){
            dp[e] = max(dp[e],dp[s]+C[s][e]);
        }
    }
    return dp[48];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(C,0,sizeof(C));
        int n;
        cin>>n;
        int s,e,c;
        for(int i=0;i<n;++i){
            cin>>s>>e>>c;
            C[s][e] = c;
        }
        cout<<solve()<<'\n';
    }
}