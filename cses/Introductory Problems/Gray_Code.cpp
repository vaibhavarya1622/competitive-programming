#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> v ={"0","1"};

    for(int i=1;i<n;++i) {
        int sz = v.size();
        for(int k=sz-1;k>=0;k--){
            v.push_back(v[k]);
        }
        for(int k=sz-1;k>=0;k--){
            v[k] = "0"+v[k];
        }
        for(int k = sz; k<v.size();++k){
            v[k] = "1"+v[k];
        }
    }
    for(string s:v){
        cout<<s<<'\n';
    }
    return 0;
}