#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array

int main(){
    int n,m;
    cin>>n>>m;

    char mat[n][m];
    int prev[n][m];
    memset(prev,-1,sizeof(prev));
    ar<int,2> begin,end;
    FOR(i,0,n){
        FOR(j,0,m){
            cin>>mat[i][j];
            if(mat[i][j] == 'A')
                begin = {i,j};
            if(mat[i][j] == 'B')
                end = {i,j};
        }
    }
    queue<ar<int,2>> q;
    q.push(begin);
    int xx[4] = {-1,1,0,0};
    int yy[4] = {0,0,-1,1};
    char dir[4] = {'U','D','L','R'};

    while(!q.empty()){
        ar<int,2> p = q.front();
        q.pop();

        if(p[0]==end[0] && p[1]==end[1]){
            break;
        }
        FOR(i,0,4){
            int new_x = p[0]+xx[i];
            int new_y = p[1]+yy[i];
            if(new_x<0 || new_y<0 || new_x>=n || new_y >= m || mat[new_x][new_y] == '#')
                continue;
         
            prev[new_x][new_y] = i;
            mat[new_x][new_y] = '#';
            q.push({new_x,new_y});
        }
    }
    if(prev[end[0]][end[1]] !=-1){
        string ans;
        int ni = end[0],nj = end[1];
        while(ni^begin[0] || nj^begin[1]) {
            ans += dir[prev[ni][nj]];
            ar<int,2> tmp = {ni,nj};
            if(prev[tmp[0]][tmp[1]] <= 1)
                ni += xx[(prev[tmp[0]][tmp[1]]+1)%2];
            else
                nj += yy[(prev[tmp[0]][tmp[1]]+1)%2+2];
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<'\n';
        cout<<ans.size()<<'\n';
        cout<<ans;
    }
    else
        cout<<"NO";
}