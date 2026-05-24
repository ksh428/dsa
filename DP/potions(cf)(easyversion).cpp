#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void initcode() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = INT_MIN;
		}
	}
	//dp(i,j): if i considder first i elements and select j of them
	int ans = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	//if (a[0] >= 0) dp[1][1] = a[0];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i - 1][j - 1] + a[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j - 1] + a[i - 1], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			//cout << dp[i][j] << " ";
			if (dp[i][j] >= 0) ans = max(ans, j);
		}
		//cout << endl;
	}
	// for (ll i = 0; i <= n; i++) {
	// 	if (dp[n][i] >= 0) ans = max(ans, i);
	// }
	cout << ans << endl;
}


int32_t main() {
	initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
