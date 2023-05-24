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
//Based on Suffix Automation
struct SuffixAuto{
    struct State{
        int len,link;
        int next[26];
        State(int _len = 0, int _link = -1):len(_len),link(_link)
        {
            memset(next,-1,sizeof(next));
        }
    };
    SuffixAuto()
    {}
    SuffixAuto(const string& s){
        init(s);
    }
    vector<State> states;
    int last;
    inline int state(int len=0, int link=-1){// this function makes a new state and return its idx
        states.emplace_back(len,link);
        return sz(states)-1;
    }
    inline void init(const string& s){
        states.reserve(2*sz(s));
        last = state();
        for(char c:s){
            extend(c);
        }
    }

    void extend(char _c){
        int c = _c-'a';
        int cur = state(states[last].len+1),P = last;
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
} sa;

const int maxN = 2e5+5;
ll K,dp[maxN];
string S,ans;

ll dfs_dp(int u = 0){
    if(dp[u]) return dp[u];
    FOR(i,0,26){
        if(sa.states[u].next[i] != -1){
            dp[u] += dfs_dp(sa.states[u].next[i]);
        }
    }
    return dp[u]+=1;
}
void dfs(int u = 0){
    if(K == 0)
        return;
    else
        K--;
    FOR(i,0,26){
        int v = sa.states[u].next[i];
        if(v != -1){
            if(K >= dp[v]){
                K -= dp[v];
            }
            else{
                ans += (char)(i+'a');
                return dfs(v);
            }
        }
    }
}
void solve(){  
    cin>>S>>K;
    sa.init(S);
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