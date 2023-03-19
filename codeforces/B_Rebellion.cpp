#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int arr[n];
        FOR(i,0,n) cin>>arr[i];

        int i=0,j=n-1;
        int cnt=0;
        while(i<j){ 
            while(j>i && arr[j] == 1) --j;
            if(arr[j] == 0){
                while(i<j && arr[i] == 0) ++i;
                if(i<j) ++cnt; 
            }
            j--,++i;
        }
        cout<<cnt<<'\n';
    }
}