#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ar array
template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    int n;
    cin>>n;
    vector<int> ans(n);
    oset<ar<int,2>> s;
    vector<ar<int,3>> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i][0]>>a[i][1],a[i][2] = i;
    }
    sort(a.begin(), a.end(),[](const ar<int,3>& x,const ar<int,3>& y){
        return (x[0]<y[0])||(x[0] == y[0] && x[1]<y[1]);
    });
    int rooms = 0;
    for(int i=0;i<n;++i){
        int pos = s.order_of_key({a[i][0],-1});
        pos-=1;
        if(pos<0){
            ++rooms;
            s.insert({a[i][1],rooms});
            ans[a[i][2]] = rooms;
        }
        else{
                auto it = s.find_by_order(pos);
                ans[a[i][2]] = (*it)[1];
                s.erase(it);
                s.insert({a[i][1],ans[a[i][2]]});
        }
    }
    cout<<s.size()<<'\n';
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}