#include<iostream>
#include <vector>
using namespace std;

#define ll long long

int main(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(n<=2 || sum%2){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        vector<int> v1,v2;
        if(n&1){
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
        }
        else{
            v1.push_back(2);
            v1.push_back(3);
            v2.push_back(1);
            v2.push_back(4);
        }
        for(int i=0;i<(n-1)/4;++i){
            int last = v2.back();
            v1.push_back(last+2);
            v1.push_back(last+3);
            v2.push_back(last+1);
            v2.push_back(last+4);
        }
        cout<<"YES"<<'\n';
        cout<<v1.size()<<'\n';
        for(auto i:v1)
            cout<<i<<" ";
        cout<<'\n';
        cout<<v2.size()<<'\n';
        for(auto i:v2){
            cout<<i<<" ";
        }
    }
    return 0;
}