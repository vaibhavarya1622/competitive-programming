#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9+7;

ll min(ll x, ll y, ll z){
    return min(x,min(y,z));
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.length(), m = s2.length();

    ll dp[n+1][m+1];
    dp[0][0] = 0;

    FOR(i,1,n+1) dp[i][0] = i;
    FOR(j,1,m+1) dp[0][j] = j;

    FOR(i,1,n+1){
        FOR(j,1,m+1){
            if(s1[i-1] != s2[j-1]){
                dp[i][j] = 1+min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);
            }
            else   
                dp[i][j] = dp[i-1][j-1];
        }
    } 
    cout<<dp[n][m];
}