#include <iostream>
#include<string.h>
#define ll long long
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int freq[26];
    memset(freq,0,sizeof(freq));
    for(char c:s){
        freq[c-'A']++;
    }
    int odd=0,even=0;
    for(int i=0;i<26;++i){
        if(freq[i]&1){
            ++odd;
        }
        else{
            ++even;
        }
    }
    if(odd>1){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    int idx=0;
    for(int i=0;i<26;++i){
        if(freq[i]&1){
            s[n/2] = i+'A';
            freq[i]--;
        }
        while(freq[i]){
            s[idx] = i+'A';
            s[n-1-idx] = i+'A';
            freq[i]-=2;
            idx++;
        }
    }
    
    cout<<s<<'\n';
    return 0;
}