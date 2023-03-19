#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

const int maxN = 1e3+5;
int red[maxN];
int blue[maxN];

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        int n;
        cin>>n;
        ll ans = 0;
        FOR(i,1,n+1) cin>>red[i+1];
        FOR(i,1,n+1) cin>>blue[i+1];

        ll ts=0;
        FOR(i,1,n+1){
            ts += red[i];
        }
        int dp[n+1][ts+1];
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;

        FOR(j,0,ts+1)
            dp[0][j] = 0;
        FOR(i,1,n+1)
            dp[i][0] = dp[i-1][0]+blue[i];

        FOR(i,1,n+1){
            FOR(j,1,ts+1){
                if(dp[i][j-red[i]] != -1){
                    
                }
            }
        }
        cout<<ans<<'\n';
    }
}