
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
void buildtree(int a[], int tree[], int s, int e, int i) {
      if (s == e) {
            tree[i] = a[s];
            return;
      }
      int m = (s + e) / 2;
      buildtree(a, tree, s, m, 2 * i);
      buildtree(a, tree, m + 1, e, 2 * i + 1);
      tree[i] = tree[2 * i] + tree[2 * i + 1];
}
void updatetree(int a[], int tree[], int s, int e, int i, int idx, int val) {
      if (s == e) {
            a[idx] = val;
            tree[i] = val;
            return;
      }
      int m = (s + e) / 2;
      if (idx > m) {
            updatetree(a, tree, m + 1, e, 2 * i + 1, idx, val);

      } else {
            updatetree(a, tree, s, m, 2 * i, idx, val);

      }
      tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int query(int tree[], int s, int e, int i, int left, int right) {
      //completely outside range
      if (s > right or e < left) return 0;
      //completely inside range
      if (s >= left and e <= right) return tree[i];
      //partially inside and outside
      int m = (s + e) / 2;
      int ansl = query(tree, s, m, 2 * i, left, right);
      int ansr = query(tree, m + 1, e, 2 * i + 1, left, right);
      return ansr + ansl;
}

void solve() {
      int a[] = {1, 2, 3, 4, 5};
      int tree[10];
      buildtree(a, tree, 0, 4, 1);
      for (int i = 1; i < 10; i++) {
            cout << tree[i] << " ";
      }
      cout << endl;
      updatetree(a, tree, 0, 4, 1, 2, 10);
      for (int i = 1; i < 10; i++) {
            cout << tree[i] << " ";
      }
      cout << endl;
      int ans = query(tree, 0, 4, 1, 2, 4);
      cout << ans;
}


int32_t main() {
      initcode();
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      solve();
      return 0;
}
