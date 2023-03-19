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

int n,m;
const int maxN = 1e5+5;
const int maxM = 2e5+5;
vi adj[maxN];
vi eu(maxM), ev(maxM), used(maxM), in(maxN);
vi ans;

void dfs(int u=1){
    while(adj[u].size()){
        int e = adj[u].back(); adj[u].pop_back();
        
        if(used[e]) continue;
        
        used[e] = 1;
        dfs(eu[e]^ev[e]^u);
         ans.pb(u);
    }
}

void solve(){     
    cin>>n>>m;
    FOR(i,1,m+1){
        cin>>eu[i]>>ev[i];
        adj[eu[i]].pb(i);
        in[ev[i]]++;
    }
    FOR(i,1,n+1){
        if((i == 1 || i == n)&&((in[i]+adj[i].size())%2 == 0)){
            cout<<"IMPOSSIBLE";
            return;
        }
        else if(i>1 && i<n && adj[i].size() != in[i]){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    dfs();
    
    if(ans.size()!=m){
        cout<<"IMPOSSIBLE";
        return;
    }
    ans.pop_back();
    cout<<1<<' ';
    reverse(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<' ';
    cout<<n;
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