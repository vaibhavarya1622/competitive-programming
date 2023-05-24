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
void count_sort(vi& p, vi& c){
    int n = p.size();
    vi cnt(n);
    for(auto x:c) cnt[x]++;
    vi pos(n),p_new(n);
    pos[0] = 0;
    FOR(i,1,n) pos[i] = pos[i-1]+cnt[i-1];
    for(auto x:p){
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
void solve(){      
    string s;
    cin>>s;
    s += "$";
    int n = s.size();
    vi p(n),c(n);
    {
        int k = 0;
        vector<pair<char,int>> a(n);
        FOR(i,0,n) a[i] = {s[i],i};
        sort(all(a));
        FOR(i,0,n) p[i] = a[i].second;
        c[p[0]] = 0;
        FOR(i,1,n){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]]+1;
            }
        }
    }
    int k=0;
    while((1<<k)<n){
        //k->k+1
        FOR(i,0,n) p[i] = (p[i]-(1<<k)+n)%n;
        count_sort(p,c);
        vi c_new(n);
        c_new[p[0]] = 0;
        FOR(i,1,n){
            pii prev = {c[p[i-1]],c[p[i-1]+(1<<k)%n]};
            pii now = {c[p[i]],c[p[i]+(1<<k)%n]};
            if(now == prev){
                c_new[p[i]] = c_new[p[i-1]];
            }
            else{
                c_new[p[i]] = c_new[p[i-1]]+1;
            }
        }
        c = c_new;
        ++k;
    }  
    vi lcp(n);
    k = 0;
    FOR(i,0,n-1){
        int pi = c[i];
        int j = p[pi-1];
        while(s[i+k] == s[j+k]) ++k;
        lcp[pi] = k;
        k = max(k-1,0);
    }
    int max_len = 0 ;
    string ans;
    FOR(i,0,n){
       if(lcp[i]>max_len){
            max_len = lcp[i];
            ans = s.substr(p[i],max_len);
       }
    }
    if(size(ans)) cout<<ans;
    else
        cout<<-1;
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