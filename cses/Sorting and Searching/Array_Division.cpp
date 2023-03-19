#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    ll lb = *max_element(arr,arr+n), rb = (ll)1e18;
    ll ans;
    while(lb<rb){
        ll mb = (lb+rb)/2ll;
        ll ls=0,cnt=0;
        for(int i=0;i<n;++i){
            if(ls+arr[i]>mb){
                ++cnt;
                ls = 0ll;
            }
            ls += arr[i];
        }
        ++cnt;
        if(cnt>k){
            lb = mb+1ll;
        }
        else
            rb = mb;
    }
    cout<<lb;
}