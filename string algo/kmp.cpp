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
vector<int> get_lps(string s) {
      int n = s.size();
      vector<int>lps(n);
      lps[0] = 0;
      int i = 1, j = 0;
      while (i < n) {
            if (s[i] == s[j]) {
                  lps[i] = j + 1;
                  j++; i++;
            } else {
                  if (j != 0) {
                        j = lps[j - 1];
                  } else {
                        lps[i] = 0;
                        i++;
                  }
            }
      }
      return lps;
}
bool kmpsearch(string text, string pattern) {
      vector<int>lps = get_lps(pattern);
      int n = text.size();
      int m = pattern.size();
      int i = 0, j = 0;
      while (i < n and j < m) {
            if (text[i] == pattern[j]) {
                  i++;
                  j++;
            } else {
                  if (j != 0) {
                        j = lps[j - 1];
                  } else {
                        i++;
                  }
            }
      }
      if (j == m) return true;
      else return false;
}

void solve() {
      string pattern;
      cin >> pattern;
      string text;
      cin >> text;
      if (kmpsearch(text, pattern)) {
            cout << "Yes";
      } else cout << "No";
      cout << endl;
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