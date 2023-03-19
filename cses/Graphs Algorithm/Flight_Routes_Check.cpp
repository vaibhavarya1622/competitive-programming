#include<bits/stdc++.h>
using namespace std;

// The theorem used here is that if one vertex can both reach and be reached by all others, then every vertex in this graph can reach all others.


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 2e3+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;

ll n,m,u,v,wt;
ll largest = 0, cnt = 0;

vector<ll> G[maxN][2];
vector<bool> vis(maxN);

void dfs(int i,int x){
    vis[i] = true;
    for(int v:G[i][x]){
        if(!vis[v])
            dfs(v,x);
    }
}

int main(){
    cin>>n>>m;

    FOR(i,0,m){
        cin>>u>>v;
        G[u][0].push_back(v);//0 is forward graph and 1 is reverse graph
        G[v][1].push_back(u);
    }
    dfs(1,0);
    FOR(i,1,n+1){
        if(!vis[i]){
            cout<<"NO"<<nl;
            cout<<1<<' '<<i;
            return 0;
        }
    }
    FOR(i,1,n+1) vis[i] = false;
    dfs(1,1);
    FOR(i,1,n+1){
        if(!vis[i]){
            cout<<"NO"<<nl;
            cout<<i<<' '<<1;
            return 0;
        }
    }
    cout<<"YES"<<nl;
}