#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
    vector<int> dp(1<<10);
	dp[0] = 1;
	for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            vector<int> new_dp(1<<10);
            for (int mask = 0; mask < (1 << n); mask++) {
                new_dp[mask] = dp[mask ^ (1 << i)]; // Horizontal/no tile
                if (i && !(mask & (1 << i)) && !(mask & (1 << i - 1))) //  Vertical tile
                    new_dp[mask] += dp[mask ^ (1 << i - 1)];

                if (new_dp[mask] >= MOD) new_dp[mask] -= MOD;
            }
            swap(dp,new_dp);
	}
	cout << dp[0];
	return 0;
}