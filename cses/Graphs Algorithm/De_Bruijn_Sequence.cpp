//eulerian cycle in directed graph
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
// #define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int maxN = 1e4+5;
vi adj[maxN];
vi used(maxN);
int n;
vi eu(maxN);
vi ev(maxN), ans;
 
void dfs(int u = 0){
    while(adj[u].size()){
        int e = adj[u].back();
        adj[u].pop_back();
        if(used[e]) continue;
        used[e] = 1;
 
        // cout<<u<<' '<<e<<' '<<eu[e]<<' '<<ev[e]<<'\n';
        dfs(eu[e]^ev[e]^u);// the expression will select the other end of the edge
        ans.push_back(e);
    }
}
 
void solve(){ 
    cin>>n;
    for(int i=0;i<1<<n;i++){
        eu[i] = i/2;
        ev[i] = i&((1<<n-1)-1);
        adj[eu[i]].push_back(i);
        adj[ev[i]].push_back(i);
    }
    dfs();
    for(int i=0;i<n-1;++i) cout<<0;
    for(int x:ans) cout<<x%2;
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