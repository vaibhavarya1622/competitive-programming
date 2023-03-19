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
struct node{
    ll sum;
    ll pre;
    node():sum(0),pre(0)
    {}
    node(ll s, ll pre):sum(s),pre(pre)
    {}
    friend node operator+(const node& a, const node& b){
        return {a.sum+b.sum,max(a.pre,a.sum+b.pre)};
    }
};
struct Segment{
    int n;
    vector<node> t;
    Segment(vl& a){
        int sz = a.size();
        this->n = sz;
        int powOftwo = 1;
        while(powOftwo<=sz)
            powOftwo <<= 1;
        
        t.resize(powOftwo*2);
        build(a,1,1,n);
    }
    void build(vl& a, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v].sum = a[tl-1];t[v].pre = max(a[tl-1],0);
        }
        else{
            ll tm = (tl+tr)/2;
            build(a,2*v,tl,tm);
            build(a,2*v+1,tm+1,tr);
            t[v] = t[2*v]+t[2*v+1];
        }
    }
    void update(ll v, ll tl, ll tr,ll pos, ll new_val){
        if(tl == tr){
            t[v].sum = new_val;t[v].pre = max(new_val,0);
        }
        else{
            ll tm = (tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else    
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v] = t[2*v]+t[2*v+1];
        }
    }
    node qry(ll v, ll tl, ll tr, ll l, ll r){
        if(l>r) return {0,0};
        if(l == tl && r == tr) return t[v];

        ll tm = (tl+tr)/2;
        return qry(2*v,tl,tm,l,min(r,tm))+qry(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
};

template<class T> struct LSegment{
    T U = -1e18;
    int n;
    vector<T> t,lz;
    LSegment(vl& a){
        int sz = a.size();
        this->n = sz;
        ll powOftwo = 1;
        while(powOftwo <= sz){
            powOftwo <<= 1;
        }
        t.assign(powOftwo*2,U);
        lz.assign(powOftwo*2,0);
        build(a,1,1,n);
    }

    void push(ll v, ll tl, ll tr){
        t[v] += lz[v];
        if(tl != tr){
            lz[2*v] += lz[v];
            lz[2*v+1] += lz[v];
        }
        lz[v] = 0;
    }
    void build(vl& a, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = a[tl-1];
        }
        else{
            ll tm = (tl+tr)/2;
            build(a,2*v,tl,tm);
            build(a,2*v+1,tm+1,tr);
            t[v] = max(t[2*v],t[2*v+1]);
        }
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T new_val){// l and r is the range in which i want updates
        push(v,tl,tr);
        if(l>tr || tl>r) return;
        if(tl>=l && tr<=r){
            lz[v] += new_val;
            push(v,tl,tr);
            return;
        }
        ll tm = (tl+tr)/2;
        update(2*v,tl,tm,l,r,new_val);
        update(2*v+1,tm+1,tr,l,r,new_val);
        t[v] = max(t[2*v],t[2*v+1]);
    }
    T qry(ll v, ll tl, ll tr, ll l, ll r){
        if(r == 0) return 0;
        push(v,tl,tr);
        if(l>tr || tl>r) return U;
        if(tl>=l && tr<=r){ return t[v];}
        ll tm = (tl+tr)/2;
        return max(qry(2*v,tl,tm,l,min(r,tm)),qry(2*v+1,tm+1,tr,max(l,tm+1),r));
    }
    void print(){
        cout<<"TREE:\t";
        for(int i=1;i<t.size();++i){
            cout<<t[i]<<' ';
        }
        cout<<'\n';
        cout<<"LAZY:\t";
        for(int i=1;i<lz.size();++i){
            cout<<lz[i]<<' ';
        }
        cout<<'\n';
        
    }
};
void solve(){  
    ll n,q;
    cin>>n>>q;
    vl arr(n),ps(n);

    
    FOR(i,0,n) cin>>arr[i];
    ps[0] = arr[0];
    FOR(i,1,n) ps[i] = ps[i-1]+arr[i];
    // Segment tree(arr);
    LSegment<ll> tree(ps);
    FOR(_,0,q){
        ll a,b,c;
        cin>>c>>a>>b;
        if(c == 1){
            ll diff = b-arr[a-1];
            tree.update(1,1,n,a,n,diff);
            arr[a-1] = b;
        }
        else{
            cout<<max(tree.qry(1,1,n,a,b)-tree.qry(1,1,n,a-1,a-1),0)<<'\n';
            // cout<<tree.qry(1,1,n,a-1,b-1)<<'\n';
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

