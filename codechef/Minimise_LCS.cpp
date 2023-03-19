#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)

int main() {
	// your code goes here
	int t;
	cin>>t;
	FOR(_,0,t){
        int n;
        cin>>n;
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    vector<int> f1(26,0);
	    vector<int> f2(26,0);
	    
	    for(char ch:s1){
	        f1[ch-'a']++;
	    }
	    for(char ch:s2){
	        f2[ch-'a']++;
	    }
	    int ans=0;
	    for(int i=0;i<26;++i){
	        if(f1[i]!=0 && f2[i]!=0){
	            ans = max(ans,min(f1[i],f2[i]));
	        }
	    }
	   cout<<ans<<'\n';
	}
	return 0;
}
