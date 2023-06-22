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
    for(int i=0;i<n;++i){
        P pt1,pt2,pt3;
        pt1.read();
        pt2.read();
        pt3.read();

        if(pt1.triangle(pt2,pt3)>0){
            cout<<"LEFT\n";
        }
        else if(pt1.triangle(pt2,pt3)<0){
            cout<<"RIGHT\n";
        }
        else
            cout<<"TOUCH\n";
    }

}