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
struct Node{
    char val;
    int weight, size;
    bool rev;
    Node *left, *right;

    Node(char c):val(c),weight(rand()),size(1),left(NULL),right(NULL),rev(0)
    {}
} *root;

int size(Node* t){
    return t?t->size:0;
}

void push(Node* node){
    if(node && node->rev){
        node->rev = 0;
        swap(node->left,node->right);
        if(node->left) node->left->rev ^= 1;
        if(node->right) node->right->rev ^= 1;
    }
}
void split(Node *t, Node* &left, Node* &right, int val){
    if(!t){
        left = NULL,right = NULL;
        return;
    }
    push(t);
    if(size(t->left)<val){
        split(t->right,t->right,right,val-size(t->left)-1);
        left = t;
    }
    else{
        split(t->left,left,t->left,val);
        right = t;
    }
    t->size = 1+size(t->left)+size(t->right);
}

void merge(Node* &t, Node *left, Node *right){
    push(left);
    push(right);
    if(!left){
        t = right;
        return;
    }
    if(!right){
        t = left;
        return;
    }
    if(left->weight<right->weight){
        merge(left->right, left->right, right);
        t = left;
    }
    else{
        merge(right->left,left,right->left);
        t = right;
    }
    t->size = 1+size(t->left)+size(t->right);
}

ostream& operator<<(ostream& os, Node* n){
    if(!n) return os;
    push(n);
    os<<n->left;
    os<<n->val;
    os<<n->right;
    return os;
}

void reverse(Node* t, int l, int r){
    Node* t1,*t2,*t3;
    split(t,t1,t2,l-1);
    split(t2,t2,t3,r-l+1);
    t2->rev ^= 1;
    merge(t,t1,t2);
    merge(t,t,t3);
}
void solve(){  
    int n,m;
    string S;
    std::cin>>n>>m>>S; 

    for(char c:S) merge(root,root,new Node(c));

    FOR(i,0,m){
        int a,b; std::cin>>a>>b;
        reverse(root,a,b);
    }
    cout<<root<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
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