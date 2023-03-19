#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    set<int> st{0,x};
    multiset<int> mst{x};

    for(int i=0;i<n;++i){
        cin>>x;
        auto it2 = st.upper_bound(x);
        auto it1 = it2;
        --it1;
        mst.erase(mst.find(*it2-*it1));//If you use *it2-*it1 then it will delete all occurences
        mst.insert(x-*it1);
        mst.insert(*it2-x);
        st.insert(x);
        auto ans = mst.end();
        --ans;
        cout<<*ans<<" ";
    }
    return 0;
}