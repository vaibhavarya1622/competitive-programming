#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9+7;

int main(){
    ll a,b;
    cin>>a>>b;

    ll dp[a+1][b+1];

    FOR(i,0,a+1){
        FOR(j,0,b+1){
            if(i == j)
                dp[i][j]=0;
            else{
                dp[i][j] = 1e9;
                FOR(k,1,i)
                    dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                FOR(k,1,j)
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout<<dp[a][b];
}