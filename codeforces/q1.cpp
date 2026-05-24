//https://codeforces.com/problemset/problem/1195/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long l = -1, r = n + 1;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if ((n - m) * (n - m + 1) / 2 - m > k)
            l = m;
        else
            r = m;
    }
    cout << r;
    return 0;
}
