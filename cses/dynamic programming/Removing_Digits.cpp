#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)

int main(){
    ll n;
    cin>>n;

    ll dp[n+1];
    dp[0] = 0;


    FOR(i,1,n+1){
        ll tmp = i;
        dp[i] = 1e9;
        while(tmp){
            dp[i] = min(dp[i],1+dp[i-tmp%10]);
            tmp = tmp/10;
        }
    }
    cout<<dp[n];
}