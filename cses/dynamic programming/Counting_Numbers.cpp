#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
 
ll dp[20][10][2];
vector<int> num;
 
ll call(int pos, int last, int f){
    if(pos == num.size()){
        return 1;
    }
    if(last != -1 && dp[pos][last][f] != -1) return dp[pos][last][f];
    int LMT = 9;
    if(f!=0){
        LMT = num[pos];
    }
    ll res=0ll;
    FOR(i,0,LMT+1){
        if(last == -1 || i != last){
            int nf = f && (i == LMT);
            int nlast = i;
            if(last == -1 && i == 0)
                nlast = -1;
            res += call(pos+1,nlast,nf && (i == LMT));
        }
    }
    return dp[pos][last][f] = res;
}
ll solve(ll x){
    if(x<0) return 0;
    num.clear();
    while(x>0){
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(), num.end());
    memset(dp,-1,sizeof(dp));
    return call(0,-1,1);
}
int main(){
    ll a,b;
    cin>>a>>b;
 
    cout<<solve(b)<<' '<<solve(a-1);
}