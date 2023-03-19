#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        ll n,a,q;
        cin>>n>>q;
        ll sum = 0;
        FOR(i,0,n){
            cin>>a;
            sum += a;
        }
        FOR(i,0,q){
            ll x,y;
            cin>>x>>y;
            if((y-x+1)&1) ++sum;
        }
        cout<<sum<<'\n';
    }
}