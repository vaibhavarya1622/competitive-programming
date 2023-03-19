#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'
#define ar array
const int maxN = 2e5+5;
const int mod = 1e9+7;
const ll INF =  0x3f3f3f3f3f3f3f3f;

vector<int> G(maxN);
vector<int> vis(maxN);
vector<int> pathLength(maxN);
queue<int> path;
int steps=0;
ll u,v,n;

void dfs(int i){
    path.push(i);
    if(vis[i]){
        steps += pathLength[i];
        return;
    }
    vis[i] = 1;
    ++steps;
    dfs(G[i]);
}
int main(){
    cin>>n;
    
    FOR(i,1,n+1){
        cin>>G[i];
    }
    FOR(i,1,n+1){
        if(!vis[i]){
            steps = 0;
            dfs(i);
            int decrement = 1;
            while(!path.empty()){
                if(path.front() == path.back()) decrement = 0;
                pathLength[path.front()] = steps;
                steps -= decrement;
                path.pop();
            }
        }
    }
    FOR(i,1,n+1){
        cout<<pathLength[i]<<' ';
    }
}