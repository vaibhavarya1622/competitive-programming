#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;++i) mp[arr[i]] = -1;
    int ans=0;
    int i=0,j=0;
    for(;j<n;++j){
        for(;mp[arr[j]] >= i;++i){}
        mp[arr[j]] = j;
        ans = max(ans,j-i+1);
    }
    cout<<ans<<'\n'; 
}