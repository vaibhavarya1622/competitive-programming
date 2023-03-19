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
const int maxN = 200002;
vl a(maxN),pref(maxN),ans(maxN),contrib(maxN);
vector<vector<ll>> bckt[maxN];

struct Fenwick{
    vl ft;
    ll n;

    Fenwick(ll n){
        this->n = n;
        ft.resize(n+1,0);
    }
    void update(ll i, ll val){
        for(;i<=n;i+=(i&-i))
            ft[i]+=val;
    }
    ll qry(ll i){
        ll res = 0;
        for(;i>0;i-=(i&-i))
            res += ft[i];
        return res;
    }
};

void solve(){   
    ll n,q,x,y;
    cin>>n>>q;
    FOR(i,1,n+1){
        cin>>a[i];
        pref[i] = pref[i-1]+a[i];
    }
    a[n+1] = pref[n+1] = infi;

    FOR(i,1,q+1){
        cin>>x>>y;
        bckt[x].push_back({y,i});
    }
    deque<ll> stck = {n+1};
    Fenwick tree(n);
    for(int i=n;i;i--){
        while(a[i]>=a[stck.front()]){
            tree.update(stck.front(),-contrib[stck.front()]);
            stck.pop_front();
        }
        contrib[i] = (stck.front()-i-1)*a[i]-(pref[stck.front()-1]-pref[i]);
        tree.update(i,contrib[i]);
        stck.push_front(i);
        for(auto j:bckt[i]){
            int pos = upper_bound(stck.begin(),stck.end(),j[0])-stck.begin()-1;
            ans[j[1]] = (pos?tree.qry(stck[pos-1])-tree.qry(i-1):0)+(j[0]-stck[pos])*a[stck[pos]]-(pref[j[0]]-pref[stck[pos]]);
        }
    }
    FOR(i,1,q+1)
        cout<<ans[i]<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout<<fixed<<setprecision(10);
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