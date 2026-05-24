
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
bool ok(int m, int k, int x) {
	int s = 0;
	if (m <= k) {
		s = m * (m + 1) / 2;
	} else {
		s = k * k;
		int d = m - k;
		int n1 = k - d - 1;
		s -= (n1 * (n1 + 1) / 2);
	}
	return s <= x;
}
int req(int m, int k, int x) {
	int s = 0;
	if (m <= k) {
		s = m * (m + 1) / 2;
	} else {
		s = k * k;
		int d = m - k;
		int n1 = k - d - 1;
		s -= (n1 * (n1 + 1) / 2);
	}
	return s;

}
void solve() {
	int k, x;
	cin >> k >> x;
	int ans = 0;
	int l = 1, h = 2 * k - 1;
	while (l <= h) {
		int m = l + (h - l) / 2;
		if (ok(m, k, x)) {
			ans = max(ans, m);
			l = m + 1;
		} else h = m - 1;
	}
	if (ans < 2 * k - 1 and req(ans, k, x) < x) ans++;
	cout << ans << endl;
}


int32_t main() {
	initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
