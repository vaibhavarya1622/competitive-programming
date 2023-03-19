#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORD(i, a, b) for (int i=a;i>=b;i--)
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

void solve(){  
    int n,d;
    cin>>n>>d;

    vector<ar<int,3>> v(n);
    FOR(i,0,n){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }  
    sort(v.begin(),v.end());
    priority_queue<ar<ll,2>> max_heap;
    int idx=0;
    FOR(i,1,d+1){
        while(idx<n && v[idx][0]<=i){
            max_heap.push({v[idx][2], v[idx][1]});
            ++idx;
        }
        if(max_heap.empty()) continue;
        ar<ll,2> tp = max_heap.top();max_heap.pop();
        if(tp[1]>1)
            max_heap.push({tp[0],tp[1]-1});
    }   
    ll ans=0;
    while(!max_heap.empty()){
        ar<ll,2> tp = max_heap.top();max_heap.pop();
        ans += tp[0]*tp[1];
    }
    cout<<ans<<nl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while (t--)
    {
        //write code here
        solve();        
    }
    return 0;
}