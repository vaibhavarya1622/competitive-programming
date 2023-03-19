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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
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

class Segment{
    public:
    int n;
    vector<ll> t;

    Segment(vl& a){
        this->n = a.size();
        int powOf2 = 1;
        int sz = a.size();

        while(powOf2 <= sz)
            powOf2 <<= 1;
        t.assign(powOf2*2,0);
        build(a,1,1,n);
    }
    void build(vl& a, ll v, ll tl, ll tr){
        if(tl == tr)
            t[v] = a[tl-1];
        else{
            ll tm = (tl+tr)/2;
            build(a,2*v,tl,tm);
            build(a,2*v+1,tm+1,tr);
            t[v] = max(t[2*v],t[2*v+1]);
        }
    }
    void update(ll v, ll tl, ll tr, ll pos, ll x){
        if(tl == tr)
            t[v] += x;
        else{
            ll tm = (tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,x);
            else 
                update(2*v+1,tm+1,tr,pos,x);
            t[v] = max(t[2*v],t[2*v+1]);
        }
    }
    ll qry(ll v, ll tl, ll tr, ll l, ll r){
        if(l>r) return 0;
        if(tl == l && tr == r) return t[v];
        ll tm = (tl+tr)/2;
        return max(qry(2*v,tl,tm,l,min(tm,r)),qry(2*v+1,tm+1,tr,max(tm+1,l),r));
    }
};
void solve(){  
    int n,m,x;
    cin>>n>>m;

    vector<ll> hotels(n);
    for(int i=0;i<n;++i) cin>>hotels[i];

    Segment tree(hotels);
    FOR(_,0,m){
        cin>>x;
        ll l = 1, r = n+1;
        while(l<r){
            ll mid = l+(r-l)/2;
            if(tree.qry(1,1,n,1,mid)>=x){
                r = mid;
            }
            else    
                l = mid+1;
        }
        if(l > n)
            cout<<0;
        else{
            cout<<l;
            tree.update(1,1,n,l,-x);
        }
        cout<<' ';
    }
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