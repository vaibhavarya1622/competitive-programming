#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    
    char mat[n][n];
    FOR(i,0,n)
        FOR(j,0,n)
            cin>>mat[i][j];
    
    ll dp[n][n];
    dp[0][0] = mat[0][0] != '*';
    FOR(i,1,n)
        if(mat[i][0] == '*') dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    FOR(j,1,n)
        if(mat[0][j] == '*') dp[0][j] = 0;
        else dp[0][j] = dp[0][j-1];
    FOR(i,1,n){
        FOR(j,1,n){
            if(mat[i][j] == '*') dp[i][j] = 0;
            else   dp[i][j] = dp[i-1][j] + dp[i][j-1],dp[i][j] %= mod;
        }
    }
    cout<<dp[n-1][n-1];
}