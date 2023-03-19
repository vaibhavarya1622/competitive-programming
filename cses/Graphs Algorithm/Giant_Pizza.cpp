// https://cp-algorithms.com/graph/2SAT.html#implementation
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define nl '\n'
#define ar array
const int maxN = 2e5+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxN];
vector<int> radj[maxN];
vector<int> st,component;
vector<bool> assignment, vis;
int n, m;

void add_disjunction(int a, bool na, int b, bool nb){
    //even number denotes a and odd denotes (¬ a)
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    radj[b].push_back(neg_a);
    radj[a].push_back(neg_b);
}
void dfs1(int u){
    vis[u] = true;
    for(int v:adj[u]){
        if(!vis[v])
            dfs1(v);
    }
    st.push_back(u);
}

void dfs2(int u, int cl){
    vis[u] = 1;
    component[u] = cl;
    for(int v:radj[u]){
        if(!vis[v]){
            dfs2(v,cl);
        }
    }
}
void solve_2SAT(){
    st.clear();
    vis.assign(2*m+2,false);
    FOR(i,1,2*m+2){
        if(!vis[i])
            dfs1(i);
    }
    component.assign(2*m+2,-1);
    vis.assign(2*m+2,false);
    int j = 0;
    FORD(i,2*m,1){
        if(!vis[st[i]]){
            dfs2(st[i],++j);
        }
    }

    vector<char> ans;
    for(int i=1;i<=m;i++){
        if(component[2*i] == component[2*i+1]){
            cout<<"IMPOSSIBLE";
            return;
        }
        ans.push_back(component[2*i]>component[2*i+1]?'+':'-');
    }
    FOR(i,0,m) cout<<ans[i]<<' ';
    return ;
}

int main(){
    cin>>n>>m;
    FOR(i,0,n){
        char c1,c2;
        int a,b;
        cin>>c1>>a>>c2>>b;
        add_disjunction(a,(c1 == '-'), b, (c2 == '-'));
    }
    solve_2SAT();
    return 0;
}