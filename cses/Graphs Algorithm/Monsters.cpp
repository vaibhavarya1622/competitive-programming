#include<bits/stdc++.h>
using namespace std;


#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ar array
#define nl '\n'

const int maxN = 1e3+3;
vector<string> mat(maxN);
int d1[maxN][maxN];
int idx[maxN][maxN];
int xx[4] = {-1,1,0,0};
int yy[4] = {0,0,-1,1};
bool vis[maxN][maxN];
string dir = "UDLR";
int n,m,si,sj;

void bfs(vector<ar<int,2>>& start, int d){
    queue<ar<int,3>> q;
    for(auto v:start){
        q.push({v[0],v[1],0});

    }
    while(!q.empty()){
        ar<int,3> p = q.front();
        q.pop();
        d1[p[0]][p[1]] = min(d1[p[0]][p[1]],p[2]);
        FOR(i,0,4){
            int ii = p[0]+xx[i];
            int jj = p[1]+yy[i];

            if(ii<0 || jj<0 || ii>=n || jj>=m || mat[ii][jj] != '.' || p[2]+1>=d1[ii][jj]) continue;
            q.push({ii,jj,p[2]+1});
            if(d==1){
                idx[ii][jj] = i;
            }
        }
    }
}

int main(){
    cin>>n>>m;

    FOR(i,0,n){
        cin>>mat[i];
    }
    memset(d1,0x3f3f3f3f,sizeof(d1));
    memset(idx,-1,sizeof(idx));
    vector<ar<int,2>> v1,v2;
    FOR(i,0,n){
        FOR(j,0,m){
            if(mat[i][j] == 'A'){
                si = i, sj = j;
                v1.push_back({i,j});
            }
            else if(mat[i][j] == 'M'){
                v2.push_back({i,j});
            }
        }
    }
    bfs(v2,2);
    bfs(v1,1);
    int ti=-1,tj=-1;
    FOR(i,0,n){
        if(idx[i][0] != -1 || mat[i][0] == 'A'){
            ti=i,tj=0;
            break;
        }
        if(idx[i][m-1] != -1 || mat[i][m-1] == 'A'){
            ti = i,tj=m-1;
            break;
        }
    }
    FOR(j,0,m){
        if(idx[0][j] != -1 || mat[0][j] == 'A'){
            ti = 0,tj = j;
            break;
        }
        if(idx[n-1][j] != -1 || mat[n-1][j] == 'A'){
            ti = n-1,tj = j;
            break;
        }
    }
    if(ti != -1){
        string ans;
        while(ti^si||tj^sj){
                int ii = idx[ti][tj];
                ans += dir[ii];
                
                if(ii<=1){
                    ii = (ii+1)%2;
                }
                else{
                    ii = (ii+1)%2+2;
                }
                ti += xx[ii],tj += yy[ii];
            }
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<nl;
        cout<<ans.size()<<nl;
        cout<<ans;
    }
    else{
        cout<<"NO";
    }
    
}