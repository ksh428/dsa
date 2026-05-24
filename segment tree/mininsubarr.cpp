#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;


void buildtree(int a[], int tree[], int s, int e, int i) {
      if (s == e) {
            tree[i] = a[s];
            return;
      }
      int m = (s + e) / 2;
      buildtree(a, tree, s, m, 2 * i);
      buildtree(a, tree, m + 1, e, 2 * i + 1);
      tree[i] = min(tree[2 * i],tree[2 * i + 1]);
}
void updatetree(int a[], int tree[], int s, int e, int i, int idx, int val) {
      if (s == e) {
            a[idx] = val;
            tree[i] = val;
            return;
      }
      int m = (e + s) / 2;
      if (idx > m) {
            updatetree(a, tree, m + 1, e, 2 * i + 1, idx, val);
      } else {
            updatetree(a, tree, s, m, 2 * i, idx, val);
      }
      tree[i] = min(tree[2 * i],tree[2 * i + 1]);
}
int query(int tree[], int s, int e, int i, int l, int r) {
      if (l > e or r < s) return INT_MAX;
      if (s >= l and e <= r) {
            return tree[i];
      }
      int m = (e + s) / 2;
      int la = query(tree, s, m, 2 * i, l, r);
      int ra = query(tree, m + 1, e, 2 * i + 1, l, r);
      return min(la,ra);
}
void solve() {
      int n,q;
      cin>>n>>q;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int tree[4 * n];
      buildtree(a, tree, 0, n - 1, 1);
      while(q--){
            char c;
            int l,r;
            cin>>c>>l>>r;
            if(c=='u'){
                  l--;
                  updatetree(a, tree, 0, n - 1, 1, l, r);
            }else{
                  l--;
                  r--;
                  cout<<query(tree, 0, n - 1, 1, l, r)<<endl;

            }
      }
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
