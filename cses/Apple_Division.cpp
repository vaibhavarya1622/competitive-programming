#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve(int i,vector<int64_t>& v, int64_t n, vector<int64_t> group, int64_t& ans){
    if(i==n){
        ans = min(ans,abs(group[0]-group[1]));
        return;
    }
    solve(i+1,v,n,{group[0]+v[i],group[1]},ans);
    solve(i+1,v,n,{group[0],group[1]+v[i]},ans);
}
int main(){
    int64_t n;
    cin>>n;

    vector<int64_t> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    int64_t ans = INT64_MAX;
    solve(0,v,n,{0,0},ans);
    cout<<ans<<'\n';
    return 0;
}