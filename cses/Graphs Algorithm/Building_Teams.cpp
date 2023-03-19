#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array

const int maxN = 1e5+3;

int ans[maxN];
vector<int> G[maxN];

void dfs(int x,int c=1){
    if(ans[x] != -1){
        if(ans[x] == c){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        return;
    }
    
    ans[x] = c^1;
    for(auto v:G[x]){
        dfs(v,c^1);
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;

    FOR(i,0,n+1)
        ans[i] = -1;
    FOR(i,0,m){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    FOR(i,1,n+1){
        if(ans[i] == -1){
            dfs(i);
        }
    }
    FOR(i,1,n+1)
        cout<<ans[i]+1<<" ";
}