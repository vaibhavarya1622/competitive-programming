#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        int n;
        cin>>n;
        int arr[n];
        FOR(i,0,n) cin>>arr[i];
        int zero = 0, one = 0;
        FOR(i,0,n){
            if(arr[i] == 0) zero++;
            else ++one;
        }
        if(zero == n || n == 1){
            cout<<0<<'\n';
        }
        else if(zero>one){
            cout<<one<<'\n';
        }
        else{
            one = one-zero;
            cout<<zero+one/3<<'\n';
        }
    }
}