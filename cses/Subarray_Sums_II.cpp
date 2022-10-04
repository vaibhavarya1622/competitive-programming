#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    map<ll,ll> m;
    ll sum=0;
    m[sum]++;
    ll ans=0;
    for(int i=0;i<n;++i){
        sum += arr[i];
        ans += m[sum-k];
        m[sum]++;
    }
    cout<<ans;
    return 0;
}