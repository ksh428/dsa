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
void build(int z[], string s) {
      int l = 0, r = 0;
      int n = s.size();
      for (int i = 1; i < n; i++) {
            if (i > r) {
                  //i lies out of lr range so calc new
                  l = i, r = i;
                  while (r < n and s[r - l] == s[r]) {
                        r++;
                  }
                  z[i] = r - l;
                  r--;
            } else {
                  int k = i - l;
                  if (i + z[k] <= r) { //lies between l and r z is prev c
                        z[i] = z[k];
                  } else {
                        //some part of z is b/w lr and prev calc but cal for the rest part
                        l = i;
                        while (r < n and s[r - l] == s[r]) r++;
                        z[i] = r - l;
                        r--;
                  }

            }

      }
}
void zalgo(string text, string pattern) {
      string str = pattern + "$" + text;
      int n = str.size();
      int z[n];
      for (int i = 0; i < n; i++) z[i] = 0;
      build(z, str);
      for (int i = 0; i < n; i++) {
            if (z[i] == pattern.size()) {
                  cout << i - pattern.size() - 1 << endl;
            }
      }

}

void solve() {
      string text;
      cin >> text;
      string pattern;
      cin >> pattern;
      zalgo(text, pattern);


}


int32_t main() {
      initcode();
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      solve();
      return 0;
}