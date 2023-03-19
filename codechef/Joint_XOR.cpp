#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include <numeric>
#include<cmath>
#include<iomanip>
#include<string>
typedef long double ld;
typedef long long ll;
#define nl '\n'
#define vi vector<int>
#define vll vector<ll>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define per(i,a,b) for(int i = (a); i >= (b); i--)
#define repl(i,a,b) for(ll i = (a); i < (b); i++)
#define perl(i,a,b) for(ll i = (a); i >= (b); i--)
using namespace std;
ll MOD = 1000000007;
ll MOD2 = 998244353;
int main(){
    int __;
    cin>>__;
    while(__--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int idx = 0;
        rep(i,1,n){
            if(s[i]!=s[i-1]){
                idx=i;
                break;
            }
        }
        if(idx==0){
            cout<<0<<nl;
            continue;
        }
        int l=1;
        rep(i,idx+1,n){
            if(s[i]==s[i-1]){
                l++;
            }
            else{
                break;
            }
        }
        string s1 = s.substr(idx,n-idx);
        int l2 = 0;
        if(l<idx){
            l2 = idx-l;
        }
        string s2 = s.substr(l2,n-idx);
        ll ans = 0;
        ll p = 1;
        cout<<s1<<' '<<s2<<'\n';
        per(i,n-idx-1,0){
            if(s1[i]!=s2[i]){
                ans = (ans+p)%MOD;
            }
            p = (2*p)%MOD;
        }
        cout<<ans<<nl;
    }
}