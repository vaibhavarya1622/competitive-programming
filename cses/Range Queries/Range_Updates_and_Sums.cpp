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
struct LSegment{
    vl t;
    ll n;
    vl lzSet,lzAdd;
    LSegment(vl& arr){
        this->n = arr.size();
        ll sz = 1;
        while(sz<=n)
            sz <<= 1;
        t.resize(sz*2,0);
        lzSet.resize(sz*2,0);
        lzAdd.resize(sz*2,0);
        build(1,1,n,arr);
    }
    void build(ll v, ll tl, ll tr, vl& a){
        if(tl == tr)
            t[v] = a[tl-1];
        else{
            ll tm = (tl+tr)/2;
            build(2*v,tl,tm,a);
            build(2*v+1,tm+1,tr,a);
            t[v] = t[2*v]+t[2*v+1];
        }
    }
    void push(ll v, ll tl, ll tr){
        if(lzSet[v]){
            t[v] = lzSet[v]*(tr-tl+1);
            if(tl != tr){
                t[2*v] = t[2*v+1] = lzSet[v]*(tr-tl+1)/2;
                lzSet[2*v] = lzSet[2*v+1] = lzSet[v];
                lzAdd[2*v] = lzAdd[2*v+1] = 0;
            }
            lzSet[v] = 0;
        }
        if(lzAdd[v]){
            // t[v] += lzAdd[v]*(tr-tl+1);
            if(tl != tr){
                t[2*v] += lzAdd[v]*(tr-tl+1)/2;
                lzAdd[2*v] += lzAdd[v];
                t[2*v+1] += lzAdd[v]*(tr-tl+1)/2;
                lzAdd[2*v+1] += lzAdd[v];
            }
            lzAdd[v] = 0;
        }
    }
    void updateSet(ll v, ll tl, ll tr, ll l, ll r, ll val){
        if(r<tl || l>tr) return;
        if(tl>=l && tr<=r){
            lzSet[v] = val;
            push(v,tl,tr);
            return;
        }
        push(v,tl,tr);
        ll tm = (tl+tr)/2;
        updateSet(2*v,tl,tm,l,r,val);
        updateSet(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
    }
    void updateAdd(ll v, ll tl, ll tr, ll l, ll r, ll val){
        // push(v,tl,tr);
        if(r<tl || l>tr) return;
        if(tl>=l && tr<=r){
            t[v] += val*(tr-tl+1);
            lzAdd[v] += val;
            // push(v,tl,tr);
            return;
        }
        push(v,tl,tr);
        ll tm = (tl+tr)/2;
        updateAdd(2*v,tl,tm,l,r,val);
        updateAdd(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
    }
    ll qry(ll v, ll tl, ll tr, ll l, ll r){
        if(r == 0) return 0;
        // push(v,tl,tr);
        if(r<tl || l>tr) return 0;
        if(tl>=l && tr<=r){
            // cout<<tl<<' '<<tr<<' '<<lzAdd[v]<<' '<<t[v]<<'\n';
            return t[v];
        }
        push(v,tl,tr);
        ll tm = (tl+tr)/2;
        return qry(2*v,tl,tm,l,min(r,tm))+qry(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
};

void solve(){   
    ll n,q;
    cin>>n>>q;
    vl arr(n);
    FOR(i,0,n) cin>>arr[i];
    LSegment tree(arr);
    FOR(i,0,q){
        ll t;
        cin>>t;
        if(t == 1){
            ll a,b,x;
            cin>>a>>b>>x;
            tree.updateAdd(1,1,n,a,b,x);
        }
        else if(t == 2){
            ll a,b,x;
            cin>>a>>b>>x;
            tree.updateSet(1,1,n,a,b,x);
        }
        else{
            ll a,b;
            cin>>a>>b;
            cout<<tree.qry(1,1,n,a,b)<<'\n';
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
    #ifdef rd
    cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}
