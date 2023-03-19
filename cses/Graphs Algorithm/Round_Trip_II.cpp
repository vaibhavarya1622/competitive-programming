#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxN = 1e5+3;

vector<int> G[maxN];
vector<int> color(maxN);
vector<int> parent(maxN);
int n,m,u,v;

bool dfs(int u){
    color[u] = 1;
    for(int v:G[u]){
        if(color[v] == 0){
            parent[v] = u;
            if(dfs(v)) return true;
        }
        else if(color[v] == 1){
            int t = u;
            stack<int> ans;
            while(t^v){
                ans.push(t);
                t = parent[t];
            }
            ans.push(v);
            ans.push(u);
            cout<<ans.size()<<nl;
            while(!ans.empty()){
                cout<<ans.top()<<' ';
                ans.pop();
            }
            exit(0);       
        }
    }
    color[u] = 2;
    return false;
}
int main(){
    cin>>n>>m;
  
    FOR(i,0,m){
        cin>>u>>v;
        G[u].push_back(v);
    }

    FOR(i,1,n+1){
        if(color[i] == 0 && dfs(i)){
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}