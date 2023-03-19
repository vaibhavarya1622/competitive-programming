#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,num;
    cin>>n;
    int xored=1;
    for(int i=2;i<=n;++i){
        xored^=i;
    }
    for(int i=1;i<n;++i){
        cin>>num;
        xored^=num;
    }
    cout<<xored;
    return 0;
}