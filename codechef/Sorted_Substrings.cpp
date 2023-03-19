#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long

int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        int n,ans=0;
        cin>>n;
        string s;
        cin>>s;
        bool flag = false;
        FOR(i,0,n){
            if(s[i] == '1'){
                flag = true;
            }
            else if(flag){
                flag = false;
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
}