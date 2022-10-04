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
    ll mod = 1e9+7;
    dp[0] = 1;
    FOR(i,1,x+1){
        dp[i] = 0;
            FOR(j,0,n){
                if(i-arr[j]>=0)
                    dp[i] += dp[i-arr[j]], dp[i] %= mod;
            }
    }
    cout<<dp[x];
    return 0;
}