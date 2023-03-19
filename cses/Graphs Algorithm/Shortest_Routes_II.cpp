#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
#define nl '\n'
#define ll long long

int main(){
    ll n,m,u,v,wt,q;
    cin>>n>>m>>q;

    ll G[n+1][n+1];
    memset(G,0x3f,sizeof(G));

    FOR(i,0,m){
        cin>>u>>v>>wt;
        G[u][v] = min(G[u][v],wt);
        G[v][u] = min(G[v][u],wt);
    }
    FOR(i,1,n+1) G[i][i] = 0;
    FOR(k,1,n+1){
        FOR(i,1,n+1){
            FOR(j,1,n+1){
                G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    FOR(i,0,q){
        cin>>u>>v;
        cout<<(G[u][v]>=1e18-1?-1:G[u][v])<<nl;
    }
}