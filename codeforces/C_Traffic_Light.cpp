#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c,ch;
        cin>>n>>c;
        vector<int> green;
        vector<int> other;

        FOR(i,0,n){
            cin>>ch;
            if(ch == 'g'){
                green.push_back(i+1);
            }
            else if(ch == c){
                other.push_back(i+1);
            }
        }
        if(c == 'g') {cout<<0<<'\n';continue;}
        int ans=0;
        FOR(i,0,(int)other.size()){
            auto idx = lower_bound(green.begin(), green.end(),other[i]);
            if(idx == green.end()){
                ans = max(ans,n-other[i]+green[0]);
            }
            else{
                ans = max(ans,(*idx)-other[i]);
            }
        }
        cout<<ans<<'\n';
    }
}