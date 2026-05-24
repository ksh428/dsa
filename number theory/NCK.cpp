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
int f[1000001];
void fact() {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		f[i] = (i * f[i - 1]) % m;
		f[i] % m;
	}
}
int power(int a, int b) { //(a^b)%m
	if (b == 0) return 1;
	int t = power(a, b / 2); 4
	int ans = 1;
	if (b % 2 == 0) {
		ans = (t * t) % m;
	} else {
		ans = (t * t) % m;
		ans = (ans * a) % m;
	}
	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (k > n) {
		cout << 0 << endl;
		return;
	}
	int ans = f[n];
	ans = (ans * power(n - k, m - 2)) % m;
	ans = (ans * power(k, m - 2)) % m;
	cout << ans << endl;
}


int32_t main() {
	initcode();
	fact();
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