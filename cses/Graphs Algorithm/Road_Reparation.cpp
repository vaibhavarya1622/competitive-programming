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

vector<ar<ll,2>> G[maxN];
vector<int> selected(maxN);
vector<ll> key(maxN,INF);
vector<ll> parent(maxN);

// ll prim(){
//     ll total_weight = 0;
//     set<ar<ll,2>> s;
//     s.insert({0,1});
//     key[1] = 0;
//     FOR(_,0,n){
//         if(s.empty()) return -1;
//         auto u = s.begin();
//         selected[(*u)[1]] = 1;
//         total_weight += (*u)[0];
//         s.erase(s.begin());

//         for(auto v:G[(*u)[1]]){
//             if(!selected[v[0]] && v[1]<key[v[0]]){
//                 s.erase({key[v[0]],v[0]});
//                 key[v[0]] = v[1];
//                 s.insert({key[v[0]],v[0]});
//             }
//         }
//     }
//     return total_weight;
// }
int find(int x){
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void join(int x, int y){
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

ll kruskal(priority_queue<ar<ll,3>, vector<ar<ll,3>>,greater<ar<ll,3>>>& min_heap){
    ll total_weight = 0, cnt=0;
    FOR(i,1,n+1) parent[i] = i;
     FOR(_,0,m){
        ar<ll,3> e = min_heap.top();
        min_heap.pop();

        if(find(e[1]) != find(e[2])){
            join(e[1],e[2]);
            total_weight += e[0];
            ++cnt;
        }
    }
    if(cnt != n-1) return -1;
    return total_weight;
}
int main(){
    cin>>n>>m;
    priority_queue<ar<ll,3>, vector<ar<ll,3>>,greater<ar<ll,3>>> min_heap;

    FOR(i,0,m){
        cin>>u>>v>>wt;
        min_heap.push({wt,u,v});
    }
    
    ll ans = kruskal(min_heap);
    
    if(ans == -1){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<ans;
    }
}