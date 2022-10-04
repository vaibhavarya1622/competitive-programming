#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<ll> twoSum(vector<ar<int,2>>& arr, int n,int start, int x){
    int l=start,r = n-1;
    while (l<r)
    {
        if(arr[l][0]+arr[r][0]>x)
            --r;
        else if(arr[l][0]+arr[r][0]<x)
            ++l;
        else{
            return {arr[l][1],arr[r][1]};
        }
    }
    return {};
}
vector<ll> kSum(vector<ar<int,2>>& arr, int n, int k, int start, int x){
    if(k == 2){
        return twoSum(arr,n,start,x);
    }
    for(int i=start;i<n;++i){
        auto ans = kSum(arr, n, k-1,i+1,x-arr[i][0]);
        if(ans.size()){
            ans.push_back(arr[i][1]);
            return ans;
        }
    }
    return {};
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<ar<int,2>> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i][0], v[i][1] = i+1;

    sort(v.begin(),v.end());
    auto ans = kSum(v,n,4,0,x);
    if(ans.size() == 0)
        cout<<"IMPOSSIBLE";
    else{
        for(auto i:ans){
            cout<<i<<" ";
        }
    }
}