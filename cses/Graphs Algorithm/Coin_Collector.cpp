#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORD(i, a, b) for (int i=a;i>=b;i--)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int maxN = 1e5+5;

vl groups(maxN);
vl rgraph[maxN];
vl dp(maxN);

struct Kosaraju{
    int N;
    vector<vector<int>> adj, radj;
    vector<bool> vis;
    vector<int> st,component, components;
    void init(int _N){
        N = _N;
        adj.resize(N), radj.resize(N), vis.assign(N,0),component.assign(N,0);
    }
    void ae(int u, int v){
        adj[u].pb(v);
        radj[v].pb(u);
    }
    void dfs1(int u){
        vis[u] = 1;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs1(v);
            }
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
    void gen(){
        FOR(i,1,N){
            if(!vis[i]) dfs1(i);
        }
        vis.assign(N,0);
        int cl=0;
        while (!st.empty())
        {
            if(!vis[st.back()]){
                dfs2(st.back(),++cl);
                components.pb(cl);
            }
            st.pop_back();
        } 
    }
};

ll DP(int i){
    if(dp[i]) return dp[i];
    dp[i] = groups[i];
    for(int j:rgraph[i]){
        dp[i] = max(dp[i],groups[i]+DP(j));
    }
    return dp[i];
}
void solve(){     
    int n,m,u,v;
    cin>>n>>m;

    vi coins(n+1);
    FOR(i,1,n+1) cin>>coins[i];  
    Kosaraju scc;
    scc.init(n+1);
    FOR(i,0,m){
        cin>>u>>v;
        scc.ae(u,v);
    } 
    scc.gen();
    FOR(i,1,n+1){
        groups[scc.component[i]] += coins[i];
    }
    FOR(u,1,n+1){
        for(int v:scc.adj[u]){
            if(scc.component[u] == scc.component[v]) continue;
            rgraph[scc.component[v]].pb(scc.component[u]);
        }
    }
    ll ans=0;
    for(int i:scc.components){
        ans = max(ans, DP(i));
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--)
    {
        //write code here
        solve();        
    }
    return 0;
}