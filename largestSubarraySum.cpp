#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int j, vector< vector<int > >& vec1,vector<string>& ans, int a, int b){
    if(i>=a || j>=b) return false;
    if(vec1[i][j] == 1) return false;
    
    if(i == a-1 && j == b-1){
        ans.push_back(to_string(i+1)+" "+to_string(j+1));
        return true;
    }
    ans.push_back(to_string(i+1)+" "+to_string(j+1));
    if(solve(i+1, j,vec1 ,ans, a, b) || solve(i, j+1, vec1,ans, a, b)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<string> robotInAGrid(vector< vector<int > > vec1 , int a , int b)
{
    vector<string> ans;
    if(vec1[0][0] || vec1[a-1][b-1]) return {"Not Possible"};
    if(solve(0,0,vec1,ans,a,b))
       return ans;
    else
        return {"Not Possible"};
}
int main()
{
    int a,b;
    cin>>a>>b;
    vector<vector<int> > input1(a,vector<int> (b));
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>input1[i][j];
        }
    }
    vector<string> ans = robotInAGrid(input1 ,a , b);
    for(string elem : ans)
    {
        cout<<elem<<"\n";
    }
}