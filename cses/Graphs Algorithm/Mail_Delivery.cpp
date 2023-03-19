//eulerian cycle Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit or cycle is an Eulerian Path which starts and ends on the same vertex
//this is eulerian cycle in undirected graph
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
const int maxN = 1e3+5;
const int maxM = 2e3+5;

vi adj[maxN];
vi degree(maxN);
vi used(maxM);
vi ans;
vi eu(maxM),ev(maxM);


void dfs(int u = 1){
    while(adj[u].size()){
        int e = adj[u].back();
        adj[u].pop_back();
        if(used[e]) continue;
        used[e] = 1;
        // cout<<u<<' '<<e<<' '<<eu[e]<<' '<<ev[e]<<'\n';
        dfs(eu[e]^ev[e]^u);// the expression will select the other end of the edge
        ans.push_back(u);
    }
}

void solve(){      
    int n, m, u, v;
    cin>>n>>m;

    FOR(i,0,m){
        cin>>eu[i]>>ev[i];
        adj[eu[i]].push_back(i);
        adj[ev[i]].push_back(i);
    }  
    FOR(i,1,n+1){
        if(adj[i].size()&1){
            cout<<"IMPOSSIBLE";
            return ;
        }
    }
    ans.push_back(1);
    dfs();
    if(ans.size()^m+1){// if ans size if not equal to (m+1)
        cout<<"IMPOSSIBLE";
        return;
    }
    else{
        for(int x:ans){
            cout<<x<<' ';
        }
    }
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