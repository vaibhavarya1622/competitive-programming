#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array

int main(){
    int n,m,u,v;
    cin>>n>>m;

    vector<int> G[n+1];
    FOR(i,0,m){
        cin>>u>>v;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    queue<int> q;
    q.push(1);
    int path[n+1];
    memset(path,-1,sizeof(path));
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if(s == n){
            break;
        }
        for(auto dest:G[s]){
            if(vis[dest]) continue;
            vis[dest] = 1;
            path[dest] = s;
            q.push(dest);
        }
    }
    if(path[n] != -1){
        vector<int> ans;
        ans.push_back(n);
        int pointer = n;
        while(pointer^1){
            ans.push_back(path[pointer]);
            pointer = path[pointer];
        }
        cout<<ans.size()<<'\n';
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i]<<" ";
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}