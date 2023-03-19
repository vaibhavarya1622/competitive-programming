#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

int cnt_two(int x){
    int cnt=0;
    while((x^1)&1){
        x>>=1;
        ++cnt;
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    FOR(_,0,t){
        int n;
        cin>>n;
        vector<int> arr(n);
        FOR(i,0,n) cin>>arr[i];

        int cnt=0;
        FOR(i,0,n){
            while((arr[i]^1)&1){
                arr[i]>>=1;
                ++cnt;
            }
        }
        cnt = n-cnt;
        ll ans=0;
        vector<int> twos;
        for(int idx=(n&1?n-1:n);idx>1;idx-=2){
            twos.push_back(cnt_two(idx));
        }
        sort(twos.begin(),twos.end(),greater<int>());
        int i=0;
        while(cnt>0 && i<twos.size()){
            ++ans;
            cnt -= twos[i];
            ++i;
        }
        if(cnt<=0){
            cout<<ans<<'\n';
        }
        else
            cout<<-1<<'\n';
    }
}