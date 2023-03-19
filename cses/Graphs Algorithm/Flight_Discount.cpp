#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
#define ll long long
const ll INF = 1e18+5;

struct Node{
    ll c;
    bool used;
    ll cost;
};

int main(){
    int n,m,u,v,wt;
    cin>>n>>m;

    vector<ar<ll,2>> G[n+1];
    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u].push_back({v,wt});
    }

    auto cmp = [](const Node& a, const Node& b){
        return a.cost>b.cost;
    };

    priority_queue<Node,vector<Node>,decltype(cmp)> min_heap(cmp);

    vector<ar<ll,2>> dist(n+1,{INF,INF});//dist[i][0] = not used coupon, dist[i][1] = used coupon
    min_heap.push(Node{1,0,0});//cost,used or not,curr city

    while(!min_heap.empty()){
        auto a = min_heap.top();
        min_heap.pop();
        if(dist[a.c][a.used] < a.cost) continue;
        if(a.c == n) break;
        for(auto b:G[a.c]){
            if(!a.used && dist[b[0]][1]>a.cost+b[1]/2){
                dist[b[0]][1] =  a.cost+b[1]/2;
                min_heap.push(Node{b[0],1,a.cost+b[1]/2});
            }
            if(a.cost+b[1]<dist[b[0]][a.used]){
                dist[b[0]][a.used] = a.cost+b[1];
                min_heap.push({Node{b[0],a.used,a.cost+b[1]}});
            }
        }
    }
    cout<<dist[n][1];
}