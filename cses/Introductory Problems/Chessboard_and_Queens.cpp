#include<iostream>
using namespace std;

string mat[8];

bool safe(int row,int col){
    for(int i=0;i<col;++i){
        if(mat[row][i] == 'Q') return false;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0; i--,j--){
        if(mat[i][j] == 'Q') return false;
    }
    for(int i=row+1,j = col-1;i<8 && j>=0; i++,j--){
        if(mat[i][j] == 'Q') return false;
    }
    return true;
}

void solve(int col,int& ans){
    if(col == 8){
        ++ans;
        return;
    }
    for(int row = 0;row<8;++row){
        if(mat[row][col] == '.' && safe(row,col)){
            mat[row][col] = 'Q';
            solve(col+1,ans);
            mat[row][col] = '.';
        }
    }
}
int main(){
    for(int i=0;i<8;++i){
        cin>>mat[i];
    }
    int ans = 0;
    solve(0,ans);
    cout<<ans;
    return 0;
}