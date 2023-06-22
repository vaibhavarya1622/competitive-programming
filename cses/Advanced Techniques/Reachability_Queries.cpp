#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define gc getchar_unlocked
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORD(i, a, b) for (int i=a;i>=b;i--)
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
#define ll long long
#define nl '\n' 
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define ar array
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
ll powm(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
}
    return res;
}
const int maxN = 5e4+1;
int n,m,u,v,q; 
bool vis[maxN];
vector<int> order,component,root_nodes;
vector<int> G[maxN];
vector<int> GT[maxN];
vector<int> condensed[maxN];
bitset<maxN> connections[maxN];

int roots[maxN];

void dfs1(int u,vector<int> adj[]){
    vis[u] = 1;

    for(int v:adj[u]){
        if(!vis[v])
            dfs1(v,adj);
    }
    order.pb(u);
}

void dfs2(int u){
    vis[u] = 1;
    component.pb(u);
    for(int v:GT[u]){
        if(!vis[v])
            dfs2(v);
    }
}

void solve(){  
    std::cin>>n>>m>>q;

    FOR(i,0,m) {
        std::cin>>u>>v; 
        G[u].pb(v);
        GT[v].pb(u);
    }
    FOR(i,1,n+1){
        if(!vis[i])
            dfs1(i,G);
    }
    reverse(all(order));
    memset(vis,0,sizeof(vis));
    
    for(int i:order){
        if(!vis[i]){
            dfs2(i);
            int root = component[0];
            for(int v:component){
                roots[v] = root;
            }
            root_nodes.pb(root);
            component.clear();
        }
    }
    FOR(u,1,n+1){
        for(auto v:G[u]){
            int root_u = roots[u];
            int root_v = roots[v];

            if(root_v != root_u){
                condensed[root_u].pb(root_v);
            }
        }
    }

    memset(vis,0,sizeof(vis));
    order.clear();
    for(int i:root_nodes){
        if(!vis[i])
            dfs1(i,condensed);
    }
    for(int u:order){// Here order consist of all condensed graph in toposort order
        connections[u].set(u);
        for(int v:condensed[u]){
            connections[u] |= connections[v];
        }
    }
    FOR(i,0,q){
        std::cin>>u>>v;
        if(connections[roots[u]][roots[v]])
            std::cout<<"YES\n";
        else
            std::cout<<"NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    std::cout<<fixed<<setprecision(10);
    int t = 1;
     //cin>>t;
    while (t--)
    {
        //write code here
        solve();        
    }
    assert(getchar()==EOF);
    #ifdef rd
    cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}