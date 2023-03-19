#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 2e3+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;

//tarzan's
struct Tarzan{
    int N, ti = 0,id = 0;
    vector<vector<int>> adj;
    vector<int> disc, stackMember, st, low,ans;
    void init(int _N){
        N = _N;
        adj.resize(N),disc.resize(N),low.resize(N),stackMember.resize(N),ans.resize(N);
    }
    void ae(int u, int v){
        adj[u].push_back(v);
    }
    void dfs(int u){
        low[u] = disc[u] = ++ti;
        st.push_back(u);
        stackMember[u] = 1;
        for(int v:adj[u]){
            if(disc[v] == 0){
                dfs(v);
                low[u] = min(low[u],low[v]);
            }
            else if(stackMember[v]){
                low[u] = min(low[u],disc[v]);
            }
        }
        if(low[u] == disc[u]){
            ++id;
            while(st.back() != u){
                ans[st.back()] = id;
                stackMember[st.back()] = 0;
                st.pop_back();
            }
            ans[st.back()] = id;
            stackMember[st.back()] = 0;
            st.pop_back();
        }
    }
    void gen(){
        for(int i=1;i<N;++i){
            if(disc[i]==0){
                dfs(i);
            }
        }
    }
};

struct Kosaraju{
    int id=0,N;
    vector<vector<int>> adj,radj;
    vector<int> vis,st,ans;
    void init(int _N){
        N = _N;
        adj.resize(N),radj.resize(N),vis.resize(N),ans.resize(N);
    }
    void ae(int u, int v){
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void dfs(int u){
        vis[u] = 1;
        for(int v:adj[u]){
            if(!vis[v]) dfs(v);
        }
        st.push_back(u);
    }

    void dfs2(int u,int id){
        vis[u] = 1;
        ans[u] = id;
        
        for(int v:radj[u]){
            if(!vis[v]) dfs2(v,id);
        }
    }
    void gen(){
        FOR(i,1,N){
            if(!vis[i]) dfs(i);
        }
        fill(vis.begin(),vis.end(),0);
        while(!st.empty()){
            if(!vis[st.back()]){
                dfs2(st.back(),++id);
            }
            st.pop_back();
        }
    }
};
int main(){
    int n,m,u,v;
    // struct Tarzan graph;
    struct Kosaraju graph;
    cin>>n>>m;
    graph.init(n+1);
    FOR(i,0,m){  
        cin>>u>>v;
        graph.ae(u,v);
    }
    graph.gen();
    cout<<graph.id<<'\n';
    FOR(i,1,n+1){
        cout<<graph.ans[i]<<' ';
    }
}