#include<bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<ar<ll,2>> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i][0]>>v[i][1];
    }
    ll reward = 0ll, time=0ll;
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        time += v[i][0];
        reward += v[i][1]-time;
    }
    cout<<reward;
}
