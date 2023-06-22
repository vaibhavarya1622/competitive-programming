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

void test_case(){
    P pt1,pt2,pt3,pt4;
    pt1.read();
    pt2.read();
    pt3.read();
    pt4.read();
    // in case of parallel
    if((pt2-pt1)*(pt3-pt4) == 0){
        if(pt1.triangle(pt2,pt3) != 0){
            cout<<"NO\n";
            return;
        }
        for(int rep = 0; rep<2;++rep){
            if(max(pt1.x,pt2.x)<min(pt3.x,pt4.x) || max(pt1.y,pt2.y)<min(pt3.y,pt4.y)){
                cout<<"NO\n";
                return;
            }
            swap(pt1,pt3);
            swap(pt2,pt4);
        }
        cout<<"YES\n";
        return;
    }
    else{
        for(int rep = 0; rep<2 ; ++rep){
            if(pt1.triangle(pt2,pt3)<0 && pt1.triangle(pt2,pt4)<0 || pt3.triangle(pt4,pt1)>0 && pt3.triangle(pt4,pt2)>0){
                cout<<"NO\n";
                return;
            }
            swap(pt1,pt3);
            swap(pt2,pt4);
        }
        cout<<"YES\n";
        return;
    }
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        test_case();
    }

}