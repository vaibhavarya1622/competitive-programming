#include<iostream>
#include<vector>
using namespace std;

void solve(int i,vector<int>& freq, int n,string str,vector<string>& v){
    if(i == n){
        v.push_back(str);
        return;
    }
    for(int idx=0;idx<26;++idx){
        if(freq[idx]>0){
            str+=(idx+'a');
            freq[idx]--;
            solve(i+1,freq,n,str,v);
            freq[idx]++;
            str.pop_back();
        }
    }
}
int main(){
    string s;
    cin>>s;

    vector<string> v;
    vector<int> freq(26,0);
    for(char c:s){
        freq[c-'a']++;
    }
    solve(0,freq,s.length(),"",v);
    cout<<v.size()<<'\n';
    for(string s:v){
        cout<<s<<'\n';
    }
    return 0;
}