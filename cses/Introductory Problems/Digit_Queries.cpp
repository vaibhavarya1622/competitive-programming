#include<bits/stdc++.h>
using namespace std;

long long power(long long x, long long y){
    long long res = 1;
    while(y)
    {
        if(y&1)
            res = res*x;
        x = x*x;
        y>>=1;
    }
    return res;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        long long n;
        cin>>n;
        if(n<=9ll){
            cout<<n<<'\n';
            continue;
        }
        long long tens = 1ll, i = 1ll;
        while(n>9ll*tens*i){
            n-=9ll*tens*i;
            tens*=10ll;
            ++i;
        }
        n--;
        long long x = n/i;
        long long y = n%i;
        long long ans = power(10, i-1) + x;
        string s = to_string(ans);
        cout<<s[y]<<endl;
    }
}