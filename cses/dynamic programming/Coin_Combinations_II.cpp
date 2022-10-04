#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)

int main(){
    ll n,x;
    cin>>n>>x;

    ll arr[n];
    FOR(i,0,n) cin>>arr[i];

    ll dp[x+1];
    memset(dp,0,sizeof(dp));
    ll mod = 1e9+7;
    dp[0] = 1;
    FOR(j,0,n){
            FOR(i,1,x+1){
                if(i-arr[j]>=0)
                    dp[i] += dp[i-arr[j]], dp[i] %= mod;
            }
    }
    cout<<dp[x];
    return 0;
}