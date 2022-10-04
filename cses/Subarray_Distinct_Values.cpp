#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    map<ll,ll> m;
    ll l = 0, ans = 0;

    for(int i=0;i<n;++i){
        m[arr[i]]++;
        while(m.size()>k){
            if(m[arr[l]] == 1){
                m.erase(m.find(arr[l]));
            }
            else{
                m[arr[l]]--;
            }
            ++l;
        }
        ans += (i-l+1);
    }
    cout<<ans;
    return 0;
}