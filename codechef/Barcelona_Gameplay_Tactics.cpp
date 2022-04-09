#include <iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

ll dp[1005][11];

vector<vector<int>> temp;
temp.push_back({1, 2, 3});

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    dp[0][0] = 1;
		dp[0][1] = 0;
		for(int i=1;i<=n;++i){
			dp[i][0] = (dp[i-1][1]*k);
			dp[i][0] %= mod;

			dp[i][1] = (dp[i-1][0]+dp[i-1][1]*(k-1));
			dp[i][1] %= mod;
		}
		cout<<dp[n][0]<<'\n';
	}
	return 0;
}
