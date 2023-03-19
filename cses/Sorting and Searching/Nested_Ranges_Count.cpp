#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ar array
template<typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    int n;
    cin>>n;
    
    vector<int> A(n);
    vector<int> B(n);
    vector<ar<int,3>> a(n);
    oset<ar<int,2>> b,c;

    for(int i=0;i<n;++i){
        cin>>a[i][0]>>a[i][1], a[i][2] = i;
    }
    sort(a.begin(),a.end(),[](const ar<int,3>& t1,const ar<int,3>& t2){
        return ((t1[0]<t2[0]) ||  (t1[0] == t2[0] && t1[1]>t2[1]));
    });

    for(int i=0,j=n-1;i<n;++i,j--){
        A[a[i][2]] = i-b.order_of_key({a[i][1],-1});
        B[a[j][2]] = c.order_of_key({a[j][1]+1,-1});
        b.insert({a[i][1],i});c.insert({a[j][1],i});
    }
    for(int i=0;i<n;++i){
        cout<<B[i]<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;++i){
        cout<<A[i]<<" ";
    }
    return 0;
}