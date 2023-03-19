#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;

    ll ans=0,i=1,power = 5;
    while(n/power>0)
        ans+=n/power,power*=5;
    
    cout<<ans<<'\n';
}