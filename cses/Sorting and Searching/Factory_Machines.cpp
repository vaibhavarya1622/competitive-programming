#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll check(ll arr[], ll n, ll time){
    ll cnt=0ll;
    for(int i=0;i<n;++i){
        cnt += time/arr[i];
    }
    return cnt;
}
int main(){
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    ll l = 1ll, r = (ll)1e18;
    while(l<r){
        ll mid = (l+r)/2ll;
        if(check(arr,n,mid)>=t){
            r = mid;
        }
        else
            l = mid+1;
    }
    cout<<r;
    return 0;
}