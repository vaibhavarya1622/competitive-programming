#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)

int main(){
    ll n,x;
    cin>>n>>x;

    ll arr[n];
    FOR(i,0,n) cin>>arr[i];

    pair<ll,ll> dp[1<<n];
    dp[0] = {1,0};
    FOR(s,1,1<<n){
        dp[s] = {n+1, 0};
        FOR(i,0,n){
            if(s&(1<<i)){
                auto option = dp[s^(1<<i)];
                if(option.second+arr[i]<=x){
                    option.second += arr[i];
                }
                else{
                    option.first++;
                    option.second = arr[i];
                }
                dp[s] = min(dp[s],option);
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}