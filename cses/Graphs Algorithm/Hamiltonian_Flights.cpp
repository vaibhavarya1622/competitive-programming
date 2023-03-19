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
const int maxN = 21;
vi adj[maxN];
int dp[1<<maxN][maxN];
int n,m,a,b;

ll dfs(int u=0, int mask = 1){
    if(u == n-1) return mask == (1<<n)-1;
    if(dp[mask][u]) return dp[mask][u];// states are current selected cities and the last city
    ll cnt = 0;
    for(int v:adj[u]){
        if(mask&(1<<v)) continue;
        cnt += dfs(v, mask|(1<<v));
        cnt %= mod;
    }
    return dp[mask][u] = cnt;
}
void solve(){   
    cin>>n>>m;
    FOR(i,0,m){
        cin>>a>>b; --a,--b;
        adj[a].pb(b);
    }     
    cout<<dfs();

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