#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int bit[100001];
void update(int i, int v) {
      for (; i <= 100000; i += (i & (-i))) {
            bit[i] += v;
      }
}
int query(int i) {
      int ans = 0;
      for (; i > 0; i -= (i & (-i))) {
            ans += bit[i];
      }
      return ans;
}

void solve() {
      int n;
      cin>>n;
      vector<int>v(n);
      for(int i=0;i<n;i++) cin>>v[i];
      //coordinate compression
      vector<int>t=v;
      sort(t.begin(),t.end());
      int a[n+1];
      for(int i=0;i<n;i++){
            int id=lower_bound(t.begin(),t.end(),t[i])-t.begin();
            a[i+1]=id+1;
      }
      int ans=0;
      for(int i=n;i>=1;i--){
            ans+=query(a[i]-1);
            update(a[i],1);
      }
      cout<<ans;


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
