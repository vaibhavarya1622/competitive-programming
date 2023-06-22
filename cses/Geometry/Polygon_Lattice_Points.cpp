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
//interior points using prick theorem
// i = A+b/2-1
// where A = area, b = boundary points
int main(){
    int n; cin>>n;
    vector<P> polygon(n);

    for(int i=0;i<n;++i){
        polygon[i].read();
    }
    long long boundary = 0,area=0;//area gives 2*A
    for(int i=0;i<n;++i){
        area += polygon[i]*polygon[i+1 == n?0:i+1];
        P diff = polygon[i+1==n?0:i+1]-polygon[i];
        boundary += gcd(abs(diff.x),abs(diff.y));
    }
    long long interior = (abs(area)-boundary+2)/2;
    cout<<interior<<' '<<boundary;
}