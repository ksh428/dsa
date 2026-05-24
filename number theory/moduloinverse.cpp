#include<bits/stdc++.h>
#define ll long long
#define int long long
#define m 1000000007
#define endl "\n"
using namespace std;
//USEING FERMAT THEOREM

//NOTE THIS WILL ONLY WORK IF M IS PRIME
//IF NOT USE EXTENDED EUCLID ALGO TO FIND MODINVERSE

void initcode() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
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

//FIND: (A/B)%M==A%M/(B%M)==(A%M)*(modinv(B))
void solve() {
	int a, b;
	cin >> a >> b;
	int ans = ((a % m) * (power(b, m - 2))) % m;
	cout << ans << endl;
}


int32_t main() {
	initcode();
	solve();
	return 0;
}