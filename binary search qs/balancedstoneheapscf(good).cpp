
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
//imp understand that we need to iterate from right not left!!!

bool ok(int x, int a[], int n) {//check whether every element in arr can be >=x
	vector<int>b(n, 0);
	//b[i] gives the amt which can be added to i from i+1,i+2th pos (max)
	for (int i = n - 1; i >= 2; i--) {
		if (b[i] + a[i] < x) return false;
		int d = min(a[i], b[i] + a[i] - x);//understand
		b[i - 1] += (d / 3);
		b[i - 2] += 2 * (d / 3);
	}
	if (a[0] + b[0] < x or a[1] + b[1] < x) return false;
	return true;


}

void solve() {
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	int l = *min_element(h, h + n);
	int r = *max_element(h, h + n);
	int ans;
	while (l <= r) {
		int m = (l + r) / 2;
		if (ok(m, h, n)) {
			ans = m;
			l = m + 1;
		} else r = m - 1;
	}
	cout << ans << endl;



}
//BS:MIN-MAX PROB

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
