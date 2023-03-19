#include<bits/stdc++.h>
using namespace std;


#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        ll ans = 0;
        FOR(k,1,n/2+1){
            ll tot = 0;
            ll p=1;
            FORD(l1,n-k-1,0){
                if(s[l1] != s[l1+k]){
                    tot = (tot+p)%mod;
                }
                cout<<l1<<' '<<l1+k<<' '<<tot<<'\n';
                p = (2ll*p)%mod;
            }
            ans = max(ans,tot);
        }
        cout<<ans<<'\n';
    }
}