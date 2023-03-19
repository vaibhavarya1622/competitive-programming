#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n;
    cin>>n;
    ordered_set<int> s;
    
    for(int i=1;i<=n;++i)
        s.insert(i);
    
    int pos = 0;
    while(s.size()>1){
        pos = (pos+1)%s.size();
        cout<<*s.find_by_order(pos)<<" ";
        s.erase(*(s.find_by_order(pos)));
    }
    cout<<*s.find_by_order(0);
    return 0;
}