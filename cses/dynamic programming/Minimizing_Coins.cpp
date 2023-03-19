#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,x;
    cin>>n>>x;

    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];

    ll dp[x+1];
    
    dp[0] = 0;
    for(int i=1;i<=x;++i){
        dp[i] = 1e9;
        for(int j=0;j<n;++j){
            if(i-arr[j]>=0)
                dp[i] = min(dp[i],1+dp[i-arr[j]]);
        }
    }
    if(dp[x] == 1e9)
        cout<<-1;
    else
        cout<<dp[x];
}