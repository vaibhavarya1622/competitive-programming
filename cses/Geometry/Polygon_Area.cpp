#include<bits/stdc++.h>
using namespace std;


struct P{
    int x,y;
    void read(){
        cin>>x>>y;
    }
    P operator -(const P& b) const{
        return P{x-b.x,y-b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    long long operator *(const P& b) const {
        return (long long) x*b.y-(long long)y*b.x;
    }
    long long triangle(const P& b, const P& c){
        return (b-*this)*(c-*this);
    }
};

int main(){
    int n; cin>>n;
    vector<P> polygon(n);

    for(int i=0;i<n;++i){
        polygon[i].read();
    }
    long long area = 0;
    for(int i=0;i<n;++i){
        area += polygon[i]*polygon[i+1 == n?0:i+1];
    }
    cout<<abs(area);
}