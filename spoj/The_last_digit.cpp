#include<iostream>
using namespace std;

int solve(int64_t a, int64_t b){
    int res=1;
    a%=10;
    while(b){
        if(b&1)
            res = res*a%10;
        a = a*a%10;
        b>>=1;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int64_t a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<'\n';
    }
}