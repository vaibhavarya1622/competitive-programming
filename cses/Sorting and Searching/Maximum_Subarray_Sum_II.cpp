#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(a,b) for(int i=a;i<b;++i)
#define ar array

int main(){
    ll n,a,b;
    cin>>n>>a>>b;

    ll arr[n+1];
    FOR(0,n) cin>>arr[i+1];

    arr[0] = 0;
    FOR(1,n+1) arr[i] += arr[i-1];

    multiset<ll> s;
    ll ans=-1e18;
    FOR(0,n+1){
        if(i-a>=0){
            s.insert(arr[i-a]);
        }
        if(s.size()){
            ans = max(ans,arr[i]-*s.begin());
        }
        if(i>-b>=0){
            if(s.find(arr[i-b]) != s.end())
                s.erase(s.find(arr[i-b]));
        }
    }
    cout<<ans;
}