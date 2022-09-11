#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
void Start() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}
void setIO(string name = ""){
ios_base::sync_with_stdio(0); cin.tie(0);
if(sz(name)){
freopen((name+".in").c_str(), "r", stdin);
freopen((name+".out").c_str(), "w", stdout);
}
}
#define debug(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << endl;
err(++it, args...);
}
#define Round_to_multiple(x, m) round(x / m) * m 
#define EPS 1e-9
#define MOD 1e9+7
#define Number_of_digits(x) ((int)log10(x) + 1)
#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define cin_2d(vec, n, m) for(int i = 0; i < n; ++i) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout_2d(vec, n, m) for(int i = 0; i < n; ++i, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]; ++j);
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto i : vec) cout << i << ' '
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
const char nl = '\n';
#define New_line cout << \nl;
#define ull unsigned long long
#define ll long long
#define clr(x, val) memset(x, val, sizeof(x))
#define Yes cout << "YES\n"
#define No cout << "NO\n"
void run(){
    int n,a,b;
    cin>>n;
    vector<vector<int>> timing(n,vector<int>(2));
    REP(i,0,n) cin>>timing[i][0]>>timing[i][1];
    sort(timing.begin(),timing.end(),[](vector<int>& v1,vector<int>& v2){
        return v1[0] == v2[0]?v1[1]<v2[1]:v1[0]<v2[0];
    });
    int arrival[n];
    REP(i,0,n) arrival[i] = timing[i][0];
    int dp[n+1];
    dp[n] = 0;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int idx = lower_bound(arrival+i+1,arrival+n,timing[i][1])-arrival;
        dp[i] = max(dp[i+1],1+dp[idx]);
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}
int main()
{
// Start();
int t = 1; 
// cin >> t;
while(t--)
 run();
return 0;
}