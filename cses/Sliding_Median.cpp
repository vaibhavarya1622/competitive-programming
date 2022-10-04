#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ar array

template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    ll n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    oset<ar<ll,2>> s;
    for(int i=0;i<k;++i){
        s.insert({arr[i],i});
    }
    cout<<(*s.find_by_order((k-1)/2))[0]<<" ";
    for(ll i=k;i<n;++i){
        s.insert({arr[i],i});
        s.erase({arr[i-k],i-k});
        auto it = s.find_by_order((k-1)/2);
        cout<<(*it)[0]<<" ";
    }
    return 0;

}