#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
#define nl '\n'
#define ll long long

int main(){
    ll n,m,u,v,wt;
    cin>>n>>m;

    vector<ar<ll,2>> G[n+1];
    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u].push_back({v,wt});
    }
    vector<ll> dist(n+1,0x3f3f3f3f3f3f3f3f);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> min_heap;
    min_heap.emplace(0,1);
    dist[1] = 0;
    while(!min_heap.empty()){
        pair<ll,ll> src = min_heap.top();
        min_heap.pop();
        if(src.first>dist[src.second]) continue;
        for(auto dest:G[src.second]){
            if(src.first+dest[1]<dist[dest[0]]){
                min_heap.emplace(src.first+dest[1],dest[0]);
                dist[dest[0]] = src.first+dest[1];
            }
        }
    }
    FOR(i,1,n+1)
        cout<<dist[i]<<' ';
}