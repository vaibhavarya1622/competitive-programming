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
const int maxN = 5e2+5, sigma = 26;
ll ans[maxN];
vl adj[maxN];
ll sz = 1;

struct Node{
    ll fail,cnt=0,ch[26]={};
    vl word;
} T[maxN];

void add_string(string& pat, int pos){
    int cur = 0;
    for(char c:pat){
        if(!T[cur].ch[c-'a']){
            T[cur].ch[c-'a'] = sz++;
        }
        cur = T[cur].ch[c-'a'];
    }
    T[cur].word.pb(pos);
}

void push_links(){
    int cur = 0;
    queue<int> Q;
    FOR(c,0,sigma){
        if(T[cur].ch[c]){
            T[T[cur].ch[c]].fail = cur,Q.push(T[cur].ch[c]); 
        }
        else{
            T[cur].ch[c] = 0;
        }
    }
    while(!Q.empty()){
        cur = Q.front(),Q.pop();
        int U = T[cur].fail;
        FOR(c,0,sigma){
            if(T[cur].ch[c]){
                T[T[cur].ch[c]].fail = T[U].ch[c],Q.push(T[cur].ch[c]);
            }
            else{
                T[cur].ch[c] = T[U].ch[c];
            }
        }
    }
    FOR(i,1,sz+1){
        adj[T[i].fail].pb(i);
    }
    FOR(i,1,sz+1){
        cout<<i<<": ";
        for(auto v:adj[i]) cout<<v<<' ';
        cout<<'\n';
    }
}
void run(string& txt){
    for(int i=0,cur=0;i<txt.length();++i){
        cur = T[cur].ch[txt[i]-'a'];
        T[cur].cnt++;
    }
}

ll dfs(int u){
    ll res = T[u].cnt;
    for(int v:adj[u]){
        res += dfs(v);
    }
    for(int w:T[u].word)
        ans[w] = res;
    return res;
}

void solve(){   
    string txt;cin>>txt;
    int q;cin>>q;
    FOR(i,0,q){
        string pat;cin>>pat;
        add_string(pat,i);
    }
    push_links();
    run(txt);
    dfs(0);
    FOR(i,0,q)
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