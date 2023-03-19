#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 1e4+5;
 
vector<int> G[maxN];
vector<int> vis(maxN);
vector<int> dist(maxN);
vector<int> path(maxN);
int n,m,u,v;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    FOR(i,0,m){
        cin>>u>>v;
        G[u].push_back(v);
    }
    queue<ar<int,2>> q;
    q.push({1,0});
    vis[1] = 1;
    while(!q.empty()){
        ar<int,2> from = q.front();
        q.pop();
        if(from[1]<dist[from[0]]) continue;
        for(int to:G[from[0]]){
            if(from[1]+1>dist[to]){
                dist[to] = from[1]+1;
                q.push({to,dist[to]});
                path[to] = from[0];
                vis[to] = 1;
            }
        }
    }
    if(dist[n] != 0){
        stack<int> ans;
        int t = n;
        while (t^1)
        {
            ans.push(t);
            t = path[t];
        }
        ans.push(1);
        cout<<ans.size()<<nl;
        while(!ans.empty()){
            cout<<ans.top()<<' ';
            ans.pop();
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}