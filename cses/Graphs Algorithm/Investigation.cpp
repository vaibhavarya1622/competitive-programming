#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 1e4+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;
vector<ar<int,2>> G[maxN];
vector<ll> dist(maxN,INF);
vector<ll> minf(maxN, maxN);
vector<ll> maxf(maxN);
vector<ll> cnt(maxN);

int n,m,u,v,wt;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u].push_back({v,wt});
    }
    cnt[1] = 1;
    minf[1] = 0;
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> min_heap;
    min_heap.push({0,1});
    while(!min_heap.empty()){
        ar<ll,2> u = min_heap.top();
        min_heap.pop();
  
        for(auto v:G[u[1]]){
            if(u[0]+v[1]<dist[v[0]]){
                dist[v[0]] = u[0]+v[1];
                cnt[v[0]] = cnt[u[1]];
                minf[v[0]] = 1+minf[u[1]];
                maxf[v[0]] = 1+maxf[u[1]];
                min_heap.push({dist[v[0]],v[0]});
            }
            else if(u[0]+v[1]==dist[v[0]]){
                minf[v[0]] = min(minf[v[0]], 1+minf[u[1]]);
                maxf[v[0]] = max(maxf[v[0]], 1+maxf[u[1]]);
                cnt[v[0]] += cnt[u[1]];
                cnt[v[0]] %= mod;
            }
        }
    }
    cout<<dist[n]<<' '<<cnt[n]<<' '<<minf[n]<<' '<<maxf[n];
}