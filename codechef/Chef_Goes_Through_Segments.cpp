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
    string sign[2] = {"-","+"};
    vpii arr(n);
    FOR(i,0,n){
        cin>>arr[i].first>>arr[i].second;
    }      
    
    string ans;
    int cnt=0;
    FOR(i,0,n-1){
        while(arr[i] != arr[i+1]){
            while(arr[i].first!=arr[i+1].first && abs(arr[i].first-arr[i].second)!=1){
                ans += "L";
                ans += (sign[arr[i].first<arr[i+1].first]);
                arr[i].first += (arr[i].first<arr[i+1].first)?1:-1;
            }
            if(arr[i].second!=arr[i+1].second){
                ans += "R";
                ans += (sign[arr[i].second<arr[i+1].second]);
                arr[i].second += (arr[i].second<arr[i+1].second)?1:-1;
            }
            // if(arr[i].first>arr[i+1].first && arr[i].first-1 != arr[i].second){
            //     ans += "L-";
            //     arr[i].first--;
            // }
            // else if(arr[i].first<arr[i+1].first && arr[i].first+1 != arr[i].second){
            //     ans += "L+";
            //     arr[i].first++;
            // }
            // else if(arr[i].second<arr[i+1].second && arr[i].second+1 != arr[i].first){
            //     ans += "R+";
            //     arr[i].second++;
            // }
            // else if(arr[i].second>arr[i+1].second && arr[i].second-1 != arr[i].first){
            //     ans += "R-";
            //     arr[i].second--;
            // }
        }
    }
    
    cout<<ans.size()/2<<'\n';
    if(ans.size()>=2)
        cout<<ans<<'\n';
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