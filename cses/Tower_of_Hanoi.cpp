#include<iostream>
#include<vector>
using namespace std;

void tower(int n,int from, int to, int aux,vector<string>& ans){
    if(n == 0){
        return;
    }
    tower(n-1,from,aux,to,ans);
    ans.push_back(to_string(from)+" "+to_string(to));
    tower(n-1,aux,to,from,ans);
}

int main(){
    int n;
    cin>>n;
    vector<string> ans;
    tower(n,1,3,2,ans);
    cout<<ans.size()<<'\n';
    for(string& s:ans){
        cout<<s<<'\n';
    }
    return 0;
}