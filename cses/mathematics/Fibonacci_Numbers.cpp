// If n is even then k = n/2:
// F(n) = [2*F(k-1) + F(k)]*F(k)

// If n is odd then k = (n + 1)/2
// F(n) = F(k)*F(k) + F(k-1)*F(k-1)
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

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
map<ll,ll> dp;  

ll F(ll n){
    if(n <= 1) return n;
    if(dp.find(n)!=dp.end()) return dp[n];
    if(n&1){
        ll k = (n+1)/2ll;
        dp[n] = ((F(k)%mod*F(k)%mod)%mod+(F(k-1)%mod*F(k-1)%mod)%mod)%mod;
    }
    else{
        ll k = n/2ll;
        dp[n] = ((2ll%mod*F(k-1)%mod*F(k)%mod+F(k)%mod*F(k)%mod)%mod);
    }
    return dp[n];
}
vvl mul(vvl& x, vvl& y){
    vvl r(2,vl(2));
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k)
                r[i][j] = (r[i][j]+(x[i][k]*y[k][j])%mod)%mod;
        }
    }
    return r;
}
void solve(){  
    ll n;
    cin>>n;
    if(n == 0){
        cout<<0;return;
    }
    //using matrix exponentiation
    n--;//since it is equal for n == 0 and n == 1, or if sequence starts from 0 then decrease n;
    vvl a(2,vl(2));
    for(int i=0;i<1;++i)
        a[i][i+1] = 1;
    for(int i=0;i<2;++i){
        a[1][i] = 1;
    }
    vvl ans(2,vl(2));
    for(int i=0;i<2;++i){
        ans[i][i] = 1;
    }
    while(n){
        if(n&1){
            ans = mul(ans,a);
        }
        a = mul(a,a);
        n>>=1;
    }
    cout<<ans[1][1];
    // cout<<F(n);
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