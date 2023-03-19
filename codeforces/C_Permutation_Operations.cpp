#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ar array
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
		cin >> N;
		vector<int> ans(N);
		for (int i = 1; i <= N; i++)
		{
			int x;
			cin >> x;
			ans[N - x] = i;
		}
		for (int i : ans)
			cout << i << " ";
		cout << '\n';
    }
}