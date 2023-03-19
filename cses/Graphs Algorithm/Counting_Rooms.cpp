#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)

char mat[1001][1001];
int n,m;

int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,-1,1};

void dfs(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j] == '#') return;
    mat[i][j] = '#';
    FOR(idx,0,4){
        int new_x = i+xx[idx];
        int new_y = j+yy[idx];
        dfs(new_x, new_y);
    }
}
int main(){
    
    cin>>n>>m;
    FOR(i,0,n) {
        FOR(j,0,m) {
            cin>>mat[i][j];
        }
    }

    int ans=0;

    FOR(i,0,n){
        FOR(j,0,m){
            if(mat[i][j] == '.'){
                ++ans;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
}