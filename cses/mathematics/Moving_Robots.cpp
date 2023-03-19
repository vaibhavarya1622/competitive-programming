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
bool safe(int x, int y){
    return x>=0 && y>=0 && x<8 && y<8;
}
void solve(){  
    ll k;
    cin>>k;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    double dp[k+1][8][8];
    double ans[8][8];
    FOR(i,0,8){
        FOR(j,0,8)
            ans[i][j] = 1;
    }

    FOR(i,0,8){
        FOR(j,0,8){
            FOR(t,0,k+1){
                FOR(i1,0,8){
                    FOR(j1,0,8)
                        dp[t][i1][j1] = 0;
                }
            }
            
            dp[0][i][j] = 1;
            FOR(t,0,k){
                FOR(i1,0,8){
                    FOR(j1,0,8){
                        int cnt = 0;
                        FOR(d,0,4){
                            if(safe(i1+dir[d][0],j1+dir[d][1])){
                                ++cnt;
                            }
                        }
                        FOR(d,0,4){
                            if(safe(i1+dir[d][0],j1+dir[d][1])){
                                dp[t+1][i1+dir[d][0]][j1+dir[d][1]] += dp[t][i1][j1]/cnt;
                            }
                        }
                    }
                }
            }
            FOR(i1,0,8){
                    FOR(j1,0,8){
                        ans[i1][j1] *= (1-dp[k][i1][j1]);
                }
            }
        }
    }

    double exp = 0.0;
    FOR(i,0,8){
        FOR(j,0,8){
            exp += ans[i][j];
        }
    }
    cout<<fixed<<setprecision(6)<<exp;
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