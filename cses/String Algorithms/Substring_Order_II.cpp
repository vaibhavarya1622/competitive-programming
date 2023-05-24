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
#define sz(x) x.size()
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
const int maxN = 2e5+5;
ll dp[maxN], cnt[maxN];

// https://codeforces.com/blog/entry/95004
// Build a suffix automaton on 𝑆
// . First, let 𝑐𝑛𝑡
//  denote the number of times a state appears in the string. Initially, we let each newly created node have 𝑐𝑛𝑡=1
//  and each cloned node have 𝑐𝑛𝑡=0
// . After the suffix automaton has been created, we process the nodes in order of length from largest to smallest:

// 𝑐𝑛𝑡[𝚕𝚒𝚗𝚔(𝑢)]+=𝑐𝑛𝑡[𝑢]
// We will create another array 𝑑𝑝
//  such that 𝑑𝑝[𝑢]
//  is equal to the number of (not necessarily distinct) substrings that start at the current node. Note that

// 𝑑𝑝[𝑢]=𝑐𝑛𝑡[𝑢]+∑𝑣∈𝚝𝚛𝚊𝚗𝚜𝚒𝚝𝚒𝚘𝚗(𝑢)𝑑𝑝[𝑣]

struct SuffixAuto{
    struct State{
        int len,link;
        int next[26];
        State(int _len=0, int _link = -1):len(_len),link(_link)
        {
            memset(next,-1,sizeof(next));
        }
    };
    vector<State> states;
    int last;

    SuffixAuto(){}
    SuffixAuto(const string& s){
        init(s);
    }
    inline int state(int len = 0,int link = -1){
        states.emplace_back(len,link);
        return sz(states)-1;
    }
    void init(const string& s){
        states.reserve(2*sz(s));
        last = state();
        for(char c:s)
            extend(c);
    }

    void extend(char _c){
        int c = _c-'a';
        int cur = state(states[last].len+1),P = last;
        cnt[cur] = 1;
        while(P != -1 && states[P].next[c] == -1){
            states[P].next[c] = cur;
            P = states[P].link;
        }
        if(P == -1){
            states[cur].link = 0;
        }
        else{
            int Q = states[P].next[c];
            if(states[P].len+1 == states[Q].len){
                states[cur].link = Q;
            }
            else{
                int C = state(states[P].len+1,states[Q].link);
                cnt[C] = 0;
                copy(states[Q].next,states[Q].next+26,states[C].next);
                while(P != -1 && states[P].next[c] == Q){
                    states[P].next[c] = C;
                    P = states[P].link;
                }
                states[Q].link = states[cur].link = C;
            }
        }
        last = cur;
    }

    void debug(int u = 0, string s = "") {
        cout << "state " << u << " = " << s << " ->";
        for (int i = 0; i < 26; i++) 
            if (states[u].next[i] != -1)
                cout << ' ' << states[u].next[i];
        cout << '\n';
        for (int i = 0; i < 26; i++) 
            if (states[u].next[i] != -1)
                debug(states[u].next[i], s + (char)(i + 'a'));
    }
} sa;

string ans,S;
ll N;

ll dfs_dp(int u = 0){
    if(dp[u]) return dp[u];
    FOR(i,0,26){
        int v = sa.states[u].next[i];
        if(v != -1){
            dp[u] += dfs_dp(v);
        }
    }
    return dp[u] += cnt[u];
}

void dfs(int u = 0) {
    if(N<cnt[u])
        return;
    else
        N -= cnt[u];

    FOR(i,0,26){
        int v = sa.states[u].next[i];
        if(v != -1){
            if(N >= dp[v]){
                N -= dp[v];
            }
            else{
                ans += (char)(i+'a');
                return dfs(v);
            }
        }
    }
}

void solve(){ 
    cin>>S>>N;

    sa.init(S);
    vector<pii> v(sa.states.size());

    FOR(i,0,sa.states.size()){
        v[i] = {sa.states[i].len,i};
    }

    sort(v.begin(),v.end(),greater<pii>());
    for(auto [len,id]:v){
        if(sa.states[id].link != -1){
            cnt[sa.states[id].link] += cnt[id];
        }
    }
    cnt[0] = 1;
    dfs_dp();
    dfs();
    cout<<ans<<'\n';
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