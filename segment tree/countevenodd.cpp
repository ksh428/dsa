#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct node{
      int odd;
      int even;
};

void buildtree(int a[], node tree[], int s, int e, int i) {
      if (s == e) {
            if(a[s]&1){
                  tree[i].odd=1;
                  tree[i].even=0;
            }else {
                  tree[i].odd=0;
                  tree[i].even=1;
            }
            return;
      }
      int m = (s + e) / 2;
      buildtree(a, tree, s, m, 2 * i);
      buildtree(a, tree, m + 1, e, 2 * i + 1);
      tree[i].odd = tree[2 * i].odd + tree[2 * i + 1].odd;
      tree[i].even = tree[2 * i].even + tree[2 * i + 1].even;
}

void updatetree(int a[], node tree[], int s, int e, int i, int idx, int val) {
      if (s == e) {
            a[idx] = val;
            if(val&1){
                  tree[i].odd=1;
                  tree[i].even=0;
            }else {
                  tree[i].odd=0;
                  tree[i].even=1;
            }
            return;
      }
      int m = (e + s) / 2;
      if (idx > m) {
            updatetree(a, tree, m + 1, e, 2 * i + 1, idx, val);
      } else {
            updatetree(a, tree, s, m, 2 * i, idx, val);
      }
      tree[i].odd = tree[2 * i].odd + tree[2 * i + 1].odd;
      tree[i].even = tree[2 * i].even + tree[2 * i + 1].even;
}

node query(node tree[], int s, int e, int i, int l, int r) {
      if (l > e or r < s) {
            node ans;
            ans.odd=0;
            ans.even=0;
            return ans;
      }
      if (s >= l and e <= r) {
            return tree[i];
      }
      int m = (e + s) / 2;
      node ans;
      node la = query(tree, s, m, 2 * i, l, r);
      node ra = query(tree, m + 1, e, 2 * i + 1, l, r);
      ans.odd=la.odd+ra.odd;
      ans.even=la.even+ra.even;
      return ans;
}
void solve() {
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      node tree[4*n];
      buildtree(a,tree,0,n-1,1);
      int q;
      cin>>q;
      while(q--){
            int c,l,r;
            cin>>c>>l>>r;
            l--;

            if(c==0){
                  updatetree(a,tree,0,n-1,1,l,r);
            }else if(c==1){
                  r--;
                  node ans=query(tree,0,n-1,1,l,r);
                  cout<<ans.even<<endl;
            }else{
                  r--;
                  node ans=query(tree,0,n-1,1,l,r);
                  cout<<ans.odd<<endl;
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
