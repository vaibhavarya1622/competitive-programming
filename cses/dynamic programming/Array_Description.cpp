#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9+7;

int main(){
    ll n,m;
    cin>>n>>m;

    ll arr[n];
    FOR(i,0,n) cin>>arr[i], --arr[i];
    
    ll dp[n][m];
    memset(dp,0,sizeof(dp));

    ll ans=0ll;
    if(arr[0] == -1){
        FOR(j,0,m) dp[0][j] = 1;
    }
    else
        dp[0][arr[0]] = 1;

    FOR(i,1,n){
        if(arr[i] == -1) {
            FOR(j,0,m){
                dp[i][j] += dp[i-1][j];
                if(j>0)
                    dp[i][j] += dp[i-1][j-1];
                if(j<m-1)
                    dp[i][j] += dp[i-1][j+1]; 
                dp[i][j] %= mod;
            }
        }
        else{ 
            if(arr[i])
                dp[i][arr[i]] += dp[i-1][arr[i]-1];
            dp[i][arr[i]] += dp[i-1][arr[i]];
            if(arr[i]<m-1)
                dp[i][arr[i]] += dp[i-1][arr[i]+1];
            
            dp[i][arr[i]] %= mod;
        }
    }
    FOR(j,0,m)
        ans += dp[n-1][j], ans %= mod;
    cout<<ans<<'\n';
}