#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    ll total = 0;
    for(int i=0;i<n-1;++i)
        total += arr[i];
    
    if(arr[n-1]>total){
        cout<<total+arr[n-1]+(arr[n-1]-total);
    }
    else{
        cout<<total + arr[n-1];
    }
}