#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

int main(){
    int n;
    cin>>n;

    ll arr[n];
    FOR(i,0,n)
        cin>>arr[i];

    vector<int> dp;
    FOR(i,0,n){
        auto it = lower_bound(dp.begin(),dp.end(),arr[i]);
        if(it == dp.end()){
            dp.push_back(arr[i]);
        }
        else
            *it = arr[i];
    }
    cout<<dp.size();
}