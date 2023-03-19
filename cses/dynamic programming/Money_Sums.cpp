#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
const int mod = 1e9+7;

int main(){
    ll n;
    cin>>n;

    ll arr[n];
    FOR(i,0,n) cin>>arr[i];

    ll sum=0ll;
    FOR(i,0,n) sum += arr[i];

    bool dp[sum+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    FOR(i,0,n){
        FORD(j,sum+1,arr[i]){
            dp[j] = dp[j]|dp[j-arr[i]];
        }
    }
    ll cnt=0;
    FOR(i,1,sum+1)
        cnt += (dp[i] != 0);
    
    cout<<cnt<<'\n';
    FOR(i,1,sum+1){
        if(dp[i] != 0)
            cout<<i<<" ";
    }
}