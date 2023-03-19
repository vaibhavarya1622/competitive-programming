#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define nl '\n'

const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Node{
    ll n;
    ll nc;
};

int main(){
    ll n,m,u,v,wt;
    cin>>n>>m;

    vector<Node> G[n+1];
    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u].push_back(Node{v,wt});
    }
    vector<ll> dist(n+1, INF);
    vector<ll> path(n+1,0);
    dist[1] = 0;
    
    FOR(i,0,n){
        bool change = 0;
        FOR(u,1,n+1){
            for(auto v:G[u]){
                if(dist[u]+v.nc<dist[v.n]){
                    dist[v.n] = dist[u] + v.nc; 
                    change = true;
                    path[v.n] = u;
                    if(i == n-1){
                        vector<int> vis(n+1,0);
                        cout<<"YES\n";
                        // cout<<"BEFORE visi u is: "<<u<<nl;
                        while (!vis[u])//this loop takes u in cycle, to see the difference run the code below commenting this while loop with the below test case
                        {
                            vis[u] = 1;
                            u = path[u];
                        }
                        // cout<<"After visited: "<<u<<nl;
                        int t = u;
                        vector<int> ans;
                        ans.push_back(t);
                        // cout<<t<<' ';
                        t = path[t];
                        // int cnt =0;
                        cout<<t<<' ';
                        while(u^t){
                            ans.push_back(t);
                            t = path[t];
                            // ++cnt;
                            // cout<<t<<' ';
                        }
                        ans.push_back(t);
                        reverse(ans.begin(), ans.end());
                        for(int x:ans){
                            cout<<x<<' ';
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO";
}
// try running for below test case
// 25 50
// 19 15 27
// 13 22 -40
// 18 23 10
// 16 7 65
// 5 13 46
// 2 13 9
// 22 4 99
// 5 4 36
// 8 9 32
// 21 17 42
// 2 16 55
// 13 4 -1
// 23 18 -36
// 25 9 23
// 1 4 27
// 8 10 -35
// 25 16 -11
// 15 25 83
// 15 21 -37
// 15 23 46
// 17 20 -9
// 21 7 54
// 17 14 -46
// 22 8 30
// 15 18 0
// 1 3 50
// 6 1 11
// 9 23 29
// 22 18 86
// 9 1 73
// 8 11 -14
// 22 17 -32
// 2 21 85
// 15 7 34
// 1 12 64
// 3 2 -2
// 17 18 87
// 12 19 88
// 12 16 -30
// 6 8 30
// 25 20 46
// 13 19 94
// 16 1 4
// 19 18 17
// 3 4 -10
// 17 5 -30
// 12 15 45
// 2 23 -37
// 22 2 96
// 16 21 62