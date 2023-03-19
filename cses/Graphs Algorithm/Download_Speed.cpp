// https://cp-algorithms.com/graph/edmonds_karp.html#flow-network
// https://usaco.guide/problems/cses-1694-download-speed/solution
// just find the augmenting path through bfs adjust the flow in that path, continue this process untill any such path exist.
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
#define ar array
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll INF = 1e18+5;
const int maxN = 501;

vvl adj(maxN,vl(maxN,0));
vi vis(maxN), par(maxN);
int n,m,a,b,c;

bool reachable(){
    fill(vis.begin(),vis.end(),0);
    fill(par.begin(), par.end(), -1);
    vis[1] = 1;

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int i = q.front();
        q.pop();

        FOR(j,1,n+1){
            if(adj[i][j] && !vis[j]){
                vis[j] = 1;
                par[j] = i;
                q.push(j);
            }
        }
    }
    return vis[n];
}

void solve(){   
    cin>>n>>m;
    FOR(i,0,m){
        cin>>a>>b>>c;
        adj[a][b] += c;
    }
    ll max_flow = 0;
    while(reachable()){
        ll flow = 1e18;
        for(int cur = n; cur^1; cur = par[cur]){
            cout<<cur<<' ';
            flow = min(flow, adj[par[cur]][cur]);
        }
        max_flow += flow;
        for(int cur = n; cur^1; cur = par[cur]){
            adj[par[cur]][cur] -= flow;
            adj[cur][par[cur]] += flow;
        }
    }
    cout<<max_flow;
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

