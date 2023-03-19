#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    stack<int> st;
    for(int i=0;i<n;++i){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        if(st.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<st.top()+1<<" ";
        }
        st.push(i);
    }
    return 0;
}