#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 2e5+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;

ll n,m,u,v,wt;
ll largest = 0, cnt = 0;

vector<ar<ll,2>> G[maxN];
vector<ll> parent(maxN);
vector<ll> sz(maxN);

ll find(ll x){
    if(parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void join(ll x, ll y){
    ll px = find(x);
    ll py = find(y);
    if(sz[px]>sz[py]){
        sz[px] += sz[py];
        parent[py] = px;
        --cnt;
        largest = max(largest, sz[px]);
    }
    else{
        sz[py] += sz[px];
        parent[px] = py;
        --cnt;
        largest = max(largest, sz[py]);
    }

}

int main(){
    cin>>n>>m;
    cnt = n;
    FOR(i,1,n+1)
        sz[i] = 1,parent[i] = i;
    
    FOR(i,0,m){
        cin>>u>>v;
        if(find(u) != find(v)){
            join(u,v);
        }
        cout<<cnt<<' '<<largest<<nl;
    }
}