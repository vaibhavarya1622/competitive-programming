#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        arr[x-1] = i;
    }
    int ans=1;
    for(int i=1;i<n;++i){
        ans += arr[i]<arr[i-1];
    }
    cout<<ans<<endl;
}