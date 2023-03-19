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
struct Fenwick2D{
    ll n;
    vector<vector<int>> ft;
    Fenwick2D(ll n){
        this->n = n;
        ft.resize(n+1,vector<int>(n+1,0));
    }
    void update(ll x,ll y, ll val){
        for(x;x<=n;x+=(x&-x)){
            for(int i=y;i<=n;i+=(i&-i))
                ft[x][i] += val;
        }
    }
    ll qry(ll x, ll y){
        ll res = 0;
        for(x;x>0;x-=(x&-x)){
            for(int i=y;i>0;i-=(i&-i))
             res += ft[x][i];
        }
        return res;
    }
    ll qry(ll x1, ll y1, ll x2, ll y2){
        return qry(x2,y2)-qry(x2,y1-1)-qry(x1-1,y2)+qry(x1-1,y1-1);
    }
};
void solve(){    
    ll n,q;
    char c;
    cin>>n>>q;
    Fenwick2D tree(n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>c;
            if(c == '*')
                tree.update(j,i,1);
        }
    }
    FOR(i,0,q){
        ll a,x1,y1,x2,y2;
        cin>>a;
        if(a == 1){
            cin>>y1>>x1;
            if(tree.qry(x1,y1,x1,y1)) tree.update(x1,y1,-1);
            else tree.update(x1,y1,1);
        }
        else{
            cin>>y1>>x1>>y2>>x2;
            cout<<tree.qry(x1,y1,x2,y2)<<'\n';
        }
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