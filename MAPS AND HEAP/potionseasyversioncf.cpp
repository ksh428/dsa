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
	int ans = 0;
	int s = 0;
	multiset<int>m;//also pq
	for (int i = 0; i < n; i++) {
		s += a[i];
		m.insert(a[i]);
		ans++;
		while (s < 0) {
			s -= *(m.begin());
			m.erase(m.begin());
			ans--;
		}
	}
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
