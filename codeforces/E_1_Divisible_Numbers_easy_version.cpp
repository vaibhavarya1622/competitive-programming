#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define FORD(i,a,b) for(ll i=a;i>=b;--i)
#define ll long long

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        int ma = (a/b)*b+b;
        int mb = (b/a)*a+a;
        if(ma>a && ma <= c && mb>b && mb<=d){
            cout<<ma<<" "<<mb<<'\n';
        }
        else if(c>=2*a && d>=2*b){
            cout<<2*a<<" "<<2*b<<'\n';
        }
        else{
            cout<<-1<<" "<<-1<<'\n';
        }
    }
}