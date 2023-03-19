#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        ll a,b;
        cin>>a>>b;
        if(a == 1 || a == b) {
            cout<<"YES"<<'\n';
            continue;
        }
        int diff = b-a;
        b -= diff;
        if(diff>=a && b%a == 0) cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}