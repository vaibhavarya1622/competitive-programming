#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);

        if((a+b)%3==0 && a*2>=b)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}