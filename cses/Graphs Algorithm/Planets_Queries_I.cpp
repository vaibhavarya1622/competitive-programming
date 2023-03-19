#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 2e5+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;
const int maxD = 30;
ll parent[maxN][maxD];
ll n,q,x,y;

int jump(int a, int d){
    FOR(i,0,maxD){
        if(d&(1<<i)){
            a = parent[a][i];
        }
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n+1)    
        cin>>parent[i][0];
    
    FOR(d,1,maxD){
        FOR(i,1,n+1){
            parent[i][d] = parent[parent[i][d-1]][d-1];
        }
    }

    while(q--){
        cin>>x>>y;
        cout<<jump(x,y)<<nl;
    }
}