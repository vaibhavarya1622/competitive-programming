#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ar<int,2> twoSum(vector<ar<int,2>>& arr, int n,int start, int x){
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
    return {-1,-1};
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<ar<int,2>> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i][0], v[i][1] = i+1;

    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        auto two = twoSum(v,n,i+1,x-v[i][0]);
        if(two != ar<int,2>{-1,-1}){
            cout<<v[i][1]<<" "<<two[0]<<" "<<two[1];
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}