#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;
    cin>>n;

    ll dp[n+1];
    ll mod = 1e9+7;
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;++i){
        dp[i] = 0;
        for(int j=1;j<=6;++j)
            if(i-j>=0) dp[i] += dp[i-j], dp[i] %= mod;
    }
    cout<<dp[n];
}