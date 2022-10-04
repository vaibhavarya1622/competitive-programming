#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b;i>=a;i--)

int main(){
    ll n,x;
    cin>>n>>x;

    ll price[n];
    ll pages[n];

    FOR(i,0,n) cin>>price[i];
    FOR(i,0,n) cin>>pages[i];

    ll dp[x+1];
    memset(dp,0,sizeof(dp));
    FOR(i,0,n){
        FORD(j,price[i],x){
            dp[j] = max(dp[j], pages[i]+dp[j-price[i]]);
        }
    }
    cout<<dp[x];
}