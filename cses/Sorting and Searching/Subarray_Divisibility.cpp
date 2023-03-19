#include<iostream>
#include <cstring>
#include<map>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    map<ll,ll> m;
    ll sum=0;
    m[sum]++;
    ll ans=0;
    for(int i=0;i<n;++i){
        sum = (sum+arr[i]%n+n)%n;
        ans += m[sum];
        m[sum]++;
    }
    cout<<ans;
    return 0;
}