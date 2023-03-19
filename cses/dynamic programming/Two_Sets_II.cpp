#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
 
int main(){
    int n;
    cin>>n;
 
    ll sum=0ll;
    FOR(i,1,n+1){
        sum += i;
    }
    if(sum&1){
        cout<<0;
        return 0;
    }
    sum>>=1;
    const ll mod = 1e9+7;
    ll dp[sum+1];
    memset(dp,0,sizeof(dp));
    
    dp[0] = (mod+1)/2; //(1/2) in mod 
    FOR(i,1,n+1){
        FORD(j,sum,i){{
                dp[j] += dp[j-i];
                if(dp[j]>=mod){
                    dp[j] -= mod;
                }
            }
        }
    }
    cout<<dp[sum];//Here you can't divide by 2 instead you have to multiply with the modular multiplicative inverse of 2
}