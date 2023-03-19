#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    char prev=' ';
    int ans=0,curr=0;
    for(int i=0;i<s.length();++i){
        if(s[i]!=prev){
            prev=s[i];
            ans=max(ans,curr);
            curr=1;
        }
        else
            ++curr;
    }
    ans=max(ans,curr);
    cout<<ans;
    return 0;
}