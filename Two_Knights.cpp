#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int64_t k=1;k<=n;++k){
        int64_t a=k*k;
        int64_t ans=a*(a-1)/2;
        ans-=4*(k-1)*(k-2);
        cout<<ans<<'\n';
    }
    return 0;
}