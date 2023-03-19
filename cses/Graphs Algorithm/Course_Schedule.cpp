#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxN = 1e5+3;

vector<int> G[maxN];
vector<int> vis(maxN);
vector<int> activate(maxN);
stack<int> ans;
int n,m,u,v;

void dfs(int u){
    vis[u] = 1;
    activate[u] = 1;
    for(int v:G[u]){
        if(activate[v]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        if(!vis[v]){
            dfs(v);
        }
    }
    activate[u] = 0;
    ans.push(u);
}
int main(){
    cin>>n>>m;
    vector<int> inOrder(n+1,0);
    FOR(i,0,m){
        cin>>u>>v;
        G[u].push_back(v);
    } 
    FOR(i,1,n+1){
        if(!vis[i])
            dfs(i);
    }
    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }
}