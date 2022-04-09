#include<iostream>
using namespace std;

int solve(int x, int y, int m){
    x%=m;
    int64_t res=1;
    while(y){
        if(y&1){
            res = res*x%m;
        }
        x = x*x%m;
        y>>=1;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,m;
        cin>>x>>y>>m;
        cout<<solve(x,y,m)<<endl;
    }
}