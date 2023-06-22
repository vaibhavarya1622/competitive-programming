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
    bool operator < (const P& b) const{
        return make_pair(x,y)<make_pair(b.x,b.y);
    }
};

int main(){
    int n; cin>>n;
    vector<P> points(n);

    for(int i=0;i<n;++i){
        points[i].read();
    }

    sort(points.begin(),points.end()); // sort from left to right
    vector<P> hull;

    for(int rep=0;rep<2;++rep){
        for(P C:points){
            while(hull.size()>=2){
                P A = hull.end()[-2];
                P B = hull.end()[-1];
                if(A.triangle(B,C)<=0){ // B on the left from C
                    break; // good choice of C, don't do anything
                }
                hull.pop_back(); //remove B
            }
            hull.push_back(C);
        }
        hull.pop_back();
        reverse(points.begin(),points.end());
    }

    cout<<hull.size()<<'\n';
    for(P p:hull){
        cout<<p.x<<' '<<p.y<<'\n';
    }
}