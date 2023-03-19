#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

bool check(vector<int>& arr,int n, string& s){
    unordered_map<int,char> mp;
    for(int i=0;i<n;++i){
        if(mp.find(arr[i])!=mp.end() && mp[arr[i]] != s[i]) return false;
        else
            mp[arr[i]] = s[i];
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        FOR(i,0,n) cin>>arr[i];
        string s;
        cin>>s;
        if(check(arr,n,s)){
            cout<<"YES"<<'\n';
        }
        else
            cout<<"NO"<<'\n';
    }
}