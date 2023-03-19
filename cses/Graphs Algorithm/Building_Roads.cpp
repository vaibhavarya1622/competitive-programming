#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
const int maxN = 1e5+3;
int arr[maxN];

int parent(int x){
    if(arr[x] != x){
        arr[x] = parent(arr[x]);
    }
    return arr[x];
}
void join(int u, int v){
    int px = parent(u);
    int py = parent(v);
    arr[px] = py;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;

    FOR(i,0,n+1) arr[i] = i;
    FOR(i,0,m)
        cin>>u>>v,join(u,v);

    vector<int> main;
    FOR(i,1,n+1)
        if(arr[i] == i)
            main.push_back(i);
    
    cout<<main.size()-1<<'\n';
    FOR(i,1,main.size()){
        cout<<main[i-1]<<' '<<main[i]<<'\n';
    }
}