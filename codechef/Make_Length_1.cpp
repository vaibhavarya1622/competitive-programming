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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    if(n == 1){
        cout<<"YES"<<nl;
        return;
    }
    FOR(i,0,n){
        if(s[i] == '0'){
            if(cnt&1) {cout<<"NO"<<nl;return;}
            cnt = 0;
        }
        else{
            ++cnt;
        }
    }
    if(cnt&1){ cout<<"NO"<<nl;return;}
    cout<<"YES"<<nl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        //write code here
        solve();        
    }
    return 0;
}