#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

bool allones(int arr[], int n){
    FOR(i,0,n){
        if(arr[i] == 0) return false;
    }
    return true;
}
bool ones(int arr[], int n){
    FOR(i,0,n){
        if(arr[i] == 1) return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];

        FOR(i,0,n) cin>>arr[i];
        
        if(k == 1){
            if(allones(arr,n)){
                cout<<"YES"<<'\n';
            }
            else
                cout<<"NO"<<'\n';
        }
        if(ones(arr,n)){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    return 0;
}