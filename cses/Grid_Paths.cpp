#include<bits/stdc++.h>
using namespace std;

int dp[7][7];

void solve(int x,int y,int i, string s, int& ans) {
    if(x<0 || y<0 || x>=7 || y>=7 || i>48) return;
    if(x == 0 && y == 6){
        if(i == 48) ++ans;
        return;
    }
    if(dp[x][y]) return;
    dp[x][y] = 1;

    if(s[i] == '?' || s[i] == 'L'){
        solve(x-1,y,i+1,s,ans);
    }
    if(s[i] == '?' || s[i] == 'R'){
        solve(x+1,y,i+1,s,ans);
    }
    if(s[i] == '?' || s[i] == 'U'){
        solve(x,y-1,i+1,s,ans);
    }
    if(s[i] == '?' || s[i] == 'D'){
        solve(x,y+1,i+1,s,ans);
    }
    dp[x][y] = 0;
}
int main(){
    string s;
    cin>>s;
    int ans=0;
    solve(0,0,0,s,ans);
    cout<<ans;
}