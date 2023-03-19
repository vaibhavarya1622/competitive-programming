#include<iostream>
using namespace std;

#define ll long long
const int mod = 1e9+7;

ll solve(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return res;
}
int main(){
    ll n;
    cin>>n;

    cout<<solve(2,n)<<'\n';
}