#include<bits/stdc++.h>
using namespace std;

#define ar array

int main(){
    int n,k;
    cin>>n>>k;
    multiset<int> s;
    vector<ar<int,2>> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i][1]>>a[i][0];
    }
    sort(a.begin(), a.end());
    int ans=0;
    for(int i=0;i<n;++i){
        auto it = s.lower_bound({a[i][1]+1});
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        if(s.size()<k){
            s.insert({a[i][0]});
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}