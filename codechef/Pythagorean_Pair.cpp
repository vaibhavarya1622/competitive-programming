#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();
    int t;
    cin>>t;
    FOR(_,0,t){
        ll n;
        cin>>n;
        
        ll p=0;
        while(n%2 == 0){
            n/=2;
            ++p;
        }
        if(p&1){
            p--;n*=2;
        }
        bool flag = false;
        for(ll a=1;a<=sqrt(n);++a){
            ll y = n-a*a;ll b = sqrt(y);
            if(b*b == y){
                cout<<(a*(ll)pow(2,p/2))<<' '<<(b*(ll)pow(2,p/2))<<'\n';
                flag = true;
                break;
            }   
        }
        if(!flag){
            cout<<-1<<'\n';
        }
    }
    return 0;
}