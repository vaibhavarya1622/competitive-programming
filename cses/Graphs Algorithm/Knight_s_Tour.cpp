#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORD(i, a, b) for (int i=a;i>=b;i--)
#define ll long long
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


int x,y;
int xx[8] = {-2,-2,2,2,1,-1,-1,1};
int yy[8] = {1,-1,-1,1,-2,-2,2,2};
int mat[8][8];
void print(){
     FOR(i,0,8){
        FOR(j,0,8){
            cout<<mat[i][j]<<' ';
        }
        cout<<'\n';
    }
}
bool dfs(int u,int v,int cnt = 1){
    mat[u][v] = cnt;
    if(cnt == 61){
        print();
        return 1;
    }
    FOR(i,0,8){
        int nx = u+xx[i];
        int ny = v+yy[i];
        if(nx<0 || nx>=8 || ny<0 || ny>=8 || mat[nx][ny]>0) continue;
        if(dfs(nx,ny,cnt+1)) return 1;
    }
    mat[u][v] = 0;
    return 0;
}
void solve(){   
    cin>>y>>x;
    --x, --y;
    dfs(x,y);
   
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--)
    {
        //write code here
        solve();        
    }
    return 0;
}

// 98-98-63-59-93