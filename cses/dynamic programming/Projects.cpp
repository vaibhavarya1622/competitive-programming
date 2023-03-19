#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int main(){
    int n;
    cin>>n;

    vector<ar<ll,3>> arr(n);
    FOR(i,0,n)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    
    sort(arr.begin(),arr.end());
    
    vector<ll> start(n);
    FOR(i,0,n) start[i] = arr[i][0];
    vector<ll> dp(n+1,0);
    FORD(i,n-1,0){
        int it = lower_bound(start.begin(), start.end(), arr[i][1]+1)-start.begin();
        dp[i] = max(dp[i+1], arr[i][2]+dp[it]);
    }
    cout<<dp[0];
}