#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x,y;
    cin>>n>>m;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;++i){
        cin>>x;
        arr[x-1] = i;
        brr[i] = x;
    }
    int ans=1;
    for(int i=1;i<n;++i){
        ans += arr[i-1]>arr[i];
    }
    for(int i=0;i<m;++i){
        cin>>x>>y;
        x--,y--;
        x = brr[x]-1, y = brr[y]-1;
        if(x>0)
            ans -= arr[x-1]>arr[x];
        if(y>0)
            ans -= arr[y-1]>arr[y];
        
        swap(arr[x],arr[y]);
        if(x>0)
            ans += arr[x-1]>arr[x];
        if(y>0)
            ans += arr[y-1]>arr[y];
        cout<<ans<<endl;
    }
    return 0;
}