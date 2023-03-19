#include<bits/stdc++.h>
using namespace std;


#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
#define nl '\n'

const int maxN = 1e5+3;
int vis[maxN];
int parent[maxN];
vector<int> G[maxN];

void dfs(int u,int par = 0){
    parent[u] = par;
    vis[u] = 1;
    for(auto v:G[u]){
        if(v == parent[u]) continue;
        if(vis[v]){
            int v2 = u;
            vector<int> ans;
            while(v^v2){
                ans.push_back(v2);
                v2 = parent[v2];
            }
            ans.push_back(v);
            ans.push_back(u);
            cout<<ans.size()<<'\n';
            for(auto x:ans){
                cout<<x<<' ';
            }
            exit(0);
        }
        else{
            dfs(v,u);
        }
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    
    FOR(i,0,m){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    FOR(i,1,n+1){
        if(vis[i] == false){
            dfs(i);
        }
    }
    cout<<"IMPOSSIBLE";
}