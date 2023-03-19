#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        int n;
        cin>>n;
        ll arr[n+1];
        FOR(i,1,n+1) cin>>arr[i];
        
        vector<ll> dec(n+1,1);
        vector<ll> inc(n+1,1);
        vector<ll> incdec(n+1,1);
        dec[0] = inc[0]= incdec[0] = 0;
        FOR(i,1,n+1){
            if(arr[i-1]>arr[i]){
                dec[i] = dec[i-1]+1;
            }
        }
        FOR(i,1,n+1){
            if(arr[i]>arr[i-1]){
                inc[i] = inc[i-1]+1;
            }
        }
        FOR(i,1,n+1){
            if(arr[i-1]>arr[i])
                incdec[i] = dec[i];
            else{
                incdec[i] = inc[i]+dec[i-inc[i]+1]-1;
            }
        }
    
        ll ans=0;
        FOR(i,1,n+1){
            ans += incdec[i];
        }
        cout<<ans<<'\n';
    }
}