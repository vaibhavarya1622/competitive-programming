#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        ll b[n];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        a[0]=1,b[0]=1;
        FOR(i,1,n){
            a[i] += 2*a[i-1]+b[i-1], a[i] %= mod;
            b[i] += 4*b[i-1]+a[i-1], b[i] %= mod;
        }
        cout<<(a[n-1]+b[n-1])%mod<<'\n';
    }

}