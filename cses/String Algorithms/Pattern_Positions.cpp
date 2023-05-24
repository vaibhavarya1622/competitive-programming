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
struct Node{
    int fail, idx = -1, ch[26]={};
    vector<int> adj,word;
    string s;
} T[maxN];
ll ans[maxN];
ll vis[maxN];
int sz = 1;

void add_string(string& s, int pos){
    int cur = 0;
    for(char c:s){
        if(!T[cur].ch[c-'a']){
            T[cur].ch[c-'a'] = sz++;
        }
        T[T[cur].ch[c-'a']].s = T[cur].s+c;
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
        cur = Q.front(), Q.pop();
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
        T[T[i].fail].adj.pb(i);
        T[i].adj.pb(T[i].fail);
    }
}
void dfs2(int& u,int idx){
    // cout<<u<<' ';
    if(u == 0) return;
    vis[u] = 1;
    T[u].idx = idx;
    for(auto v:T[u].adj){
        if(!vis[v])
            dfs2(v,idx);
    }
}
void run(string& txt){
    for(int i=0,cur = 0;i<(int)txt.length();++i){
        cur = T[cur].ch[txt[i]-'a'];
        dfs2(cur,i);
    }
}

void dfs(int u){
    vis[u] = 1;
    for(auto v:T[u].adj){
        if(!vis[v])
            dfs(v);
    }
    for(auto w:T[u].word){
        if(T[u].idx != -1)
            ans[w] = min(ans[w],T[u].idx-(T[u].s.length())+2);
    }
}

void solve(){     
    fill(ans,ans+maxN,INT_MAX);
    string s; cin>>s;
    int k;cin>>k;
    FOR(i,0,k){
        string t;cin>>t;
        add_string(t,i);
    }  
    push_links();
    memset(vis,0,sizeof(vis));
    run(s);
    memset(vis,0,sizeof(vis));
    dfs(0);
    for(int i=0;i<k;++i){
        if(ans[i] != INT_MAX) cout<<ans[i]<<'\n';
        else cout<<-1<<'\n';
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