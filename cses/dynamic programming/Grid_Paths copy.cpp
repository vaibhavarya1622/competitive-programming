#include<bits/stdc++.h>
using namespace std;

// Optimize NEeded
//  if the path cannot continue forward but can turn either left or right, the grid splits 
//  into two parts that both contain unvisited squares. It is clear that we cannot visit all squares anymore, so we can terminate the search.

bool vis[7][7];

string s;
int ans;

bool safe(int x, int y){
    return x>=0 && x<7 && y>=0 && y<7 && !vis[x][y];
}
void solve(int i,int j,int idx=0) {
    if(i == 6 && j == 0){
        if(idx == 48)
            ++ans;
        return;
    }
    vis[i][j] = 1;
    
    if(safe(i,j-1) && (s[idx] == '?' || s[idx] == 'L')){
        if(!(!safe(i,j-2) && (safe(i+1,j-1) && safe(i-1,j-1))))
            solve(i,j-1,idx+1);
    }
    if(safe(i,j+1) && (s[idx] == '?' || s[idx] == 'R')){
        if(!(!safe(i,j+2) && (safe(i+1,j+1) && safe(i-1,j+1))))
            solve(i,j+1,idx+1);
    }
    if(safe(i-1,j) && (s[idx] == '?' || s[idx] == 'U')){
        if(!(!safe(i-2,j) && (safe(i-1,j+1) && safe(i-1,j-1))))
            solve(i-1,j,idx+1);
    }
    if(safe(i+1,j) && (s[idx] == '?' || s[idx] == 'D')){
        if(!(!safe(i+2,j) && (safe(i+1,j-1) && safe(i+1,j+1))))
        solve(i+1,j,idx+1);
    }
    vis[i][j] = 0;
}
int main(){
    cin>>s;
    solve(0,0);
    cout<<ans;
    return 0;
}