#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    multiset<int> st;
    int ans = 0 ;
    for(int i = 0;i < n; ++i){
        auto it = st.upper_bound(arr[i]);
        if(it == st.end()){
            ++ans;
            st.insert(arr[i]);
        }
        else{
            
            st.erase(it);
            st.insert(arr[i]);
        }
    }
    cout<<ans;
    return 0;
}