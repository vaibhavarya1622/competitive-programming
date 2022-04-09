#include<iostream>
#define ll long long
using namespace std;

const int mod = 1e9+7;

ll pow(ll x, ll y){
    ll res=1;
    while(y>0){
        if(y&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return res;
}

ll solve(ll n){
    if(n <= 3) return n;
    if(n%3 == 0) 
        return pow(3,n/3ll);
    if(n%3==1){
        return pow(3,n/3ll-1ll)*4ll%mod;
    }
    return  
        pow(3,n/3ll)*2ll%mod;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<solve(n)<<'\n';
    }
}