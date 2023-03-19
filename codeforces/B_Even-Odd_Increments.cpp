#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        vector<ll> arr(n);
        FOR(i,0,n) cin>>arr[i];
        ll odd=0ll,even=0ll,ce=0,co=0;
        FOR(i,0,n){
            if(arr[i]&1) odd += arr[i],++co;
            else even += arr[i],++ce;
        }
        FOR(i,0,q){
            ll a,b;
            cin>>a>>b;
            if(a == 0){
                even += b*ce;
                if(b&1){
                    odd += even;
                    co += ce;
                    even = 0;
                    ce = 0;
                }
            }
            else{
                odd += b*co;
                if(b&1){
                    even += odd;
                    ce += co;
                    odd = 0;
                    co = 0;
                }
            }
            cout<<even+odd<<'\n';
        }
    }
}