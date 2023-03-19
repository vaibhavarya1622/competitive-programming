#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
#define nl '\n'
#define ll long long
const ll INF = 1e18+3;

struct edge{
    int a, b, cost;
};

void dfs(int u, vector<ar<ll,2>> RG[],vector<bool>& vis){
    vis[u] = 1;
    for(auto v:RG[u]){
        if(!vis[v[0]]){
            dfs(v[0],RG,vis);
        }
    }
}
int main(){
    ll n,m,u,v,wt,q;
    cin>>n>>m;

    vector<ar<ll,2>> G[n+1];
    vector<ar<ll,2>> RG[n+1];

    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u].push_back({v,wt});
        RG[v].push_back({u,wt});
    }

    vector<bool> vis(n+1,false);
    dfs(n,RG,vis);
    vector<ll> D(n+1,-INF);
    D[1] = 0;
    FOR(i,0,n){
        bool any = false;
        FOR(u,1,n+1){
            if(!vis[u]) continue;
            for(auto v:G[u]){
                if(D[u] != -INF && D[u]+v[1]>D[v[0]]){
                    D[v[0]] = D[u]+v[1];
                    any = true;
                }
            }
        }
        if(i == n-1 && any){ 
            cout<<-1;
            return 0;
        }
    }
    cout<<D[n];
}