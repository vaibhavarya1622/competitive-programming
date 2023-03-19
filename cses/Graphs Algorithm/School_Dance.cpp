// https://www.topcoder.com/thrive/articles/Problem%20Solving%20-Solving%20Maximum%20Bipartite%20Matching%20Problem
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORD(i, a, b) for (int i=a;i>=b;i--)
#define ll long long
#define nl '\n' 
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

const int maxN = 501;
vi adj[maxN];
vi used(maxN), mt(maxN,-1);
int n,m,k,a,b,f=0;

bool try_kuhn(int u){
    if(used[u]) return 0;
    used[u] = 1;
    for(int v:adj[u]){
        if(mt[v] == -1 || try_kuhn(mt[v])){
            mt[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve(){    
    cin>>n>>m>>k;
    FOR(i,0,k){
        cin>>a>>b;
        adj[a].pb(b);
    }
    fill(mt.begin(), mt.end(), - 1);
    
    FOR(i,1,n+1){
        fill(used.begin(), used.end(), false);
        f += try_kuhn(i);
    }
    cout<<f<<nl;
    FOR(i,1,k+1){
        if(mt[i] != -1){
            cout<<mt[i]<<' '<<i<<nl;
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