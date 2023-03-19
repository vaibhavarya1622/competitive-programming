#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int main(){
    ll n;
    cin>>n;

    ll arr[n];
    ll sum=0ll;
    FOR(i,0,n)
        cin>>arr[i], sum += arr[i];
    
    ll dp[n][n];

    FORD(l,n-1,0){
        FOR(r,l,n){
            if(l == r)
                dp[l][r] = arr[l];
            else
                dp[l][r] = max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
        }
    }
    cout<<(sum + dp[0][n-1])/2;
}