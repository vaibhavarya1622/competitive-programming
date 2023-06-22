#include<bits/stdc++.h>
using namespace std;


struct P{
    long long x,y;
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
    long long triangle(const P& b, const P& c) const{
        return (b-*this)*(c-*this);
    }
};
bool intersect(P pt1, P pt2, P pt3, P pt4){
    if((pt2-pt1)*(pt3-pt4) == 0){
        if(pt1.triangle(pt2,pt3) != 0){
            return false;
        }
        for(int rep = 0; rep<2;++rep){
            if(max(pt1.x,pt2.x)<min(pt3.x,pt4.x) || max(pt1.y,pt2.y)<min(pt3.y,pt4.y)){
                return false;
            }
            swap(pt1,pt3);
            swap(pt2,pt4);
        }
        return true;
    }
    else{
        for(int rep = 0; rep<2 ; ++rep){
            if(pt1.triangle(pt2,pt3)<0 && pt1.triangle(pt2,pt4)<0 || pt3.triangle(pt4,pt1)>0 && pt3.triangle(pt4,pt2)>0){
                return false;
            }
            swap(pt1,pt3);
            swap(pt2,pt4);
        }
        return true;
    }
}

bool check_on_boundary(const P& a, const P& b, const P& c){
    if(a.triangle(b,c) != 0){
        return false; // not even collinear
    }
    return min(a.x,b.x)<=c.x && max(a.x,b.x)>=c.x
            && min(a.y,b.y)<=c.y && max(a.y,b.y)>=c.y;
}
int main(){
    int n,m;cin>>n>>m;

    vector<P> polygon(n);
    
    for(int i=0;i<n;++i) {
        polygon[i].read();
    }

    for(int i=0;i<m;++i){
        P p; p.read();
        bool lies_on_segment = false;
        P out = {p.x+1,3'000'000'000LL};
        long long cnt = 0;
        for(int j=0;j<n;++j){
            if(check_on_boundary(polygon[j],polygon[j+1 == n?0:j+1],p)){
                lies_on_segment = true;
                break;
            }
            if(intersect(p,out,polygon[j],polygon[j+1 == n?0:j+1]))
                ++cnt;
        }

        if(lies_on_segment)
            cout<<"BOUNDARY\n";
        else if(cnt%2 == 0)
            cout<<"OUTSIDE\n";
        else 
            cout<<"INSIDE\n";
    }
}