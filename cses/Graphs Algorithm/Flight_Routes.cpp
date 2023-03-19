#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main(){
    ll n,m,k,u,v,wt;
    cin>>n>>m>>k;
    vector<ar<ll,2>> G[n+1];
    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u].push_back({wt,v});
    }

    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> min_heap;
    vector<ll> ans;
    min_heap.push({0,1});
    vector<ll> dist[n+1];
  
    while(!min_heap.empty()){
        ar<ll,2> from = min_heap.top();
        min_heap.pop();
        
        if(dist[from[1]].size()>k) continue;

        dist[from[1]].push_back(from[0]);

        for(auto to:G[from[1]]){
            min_heap.push({from[0]+to[0],to[1]});
        }
    }
    FOR(i,0,k) cout<<dist[n][i]<<' ';
}