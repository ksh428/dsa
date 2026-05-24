#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
//dp+fenwick tree
const int mx=100004;

int bit[3][mx+2];

void update(int i, int j, int val) {
      for (; i <= mx; i += (i & (-i))) {
            bit[j][i] += val;
            bit[j][i]%=mod;
      }
}
int query(int i,int j) {
      int ans = 0;
      for (; i > 0; i -= (i & (-i))) {
            ans += bit[j][i];
            ans%=mod;
      }
      return ans;
}
//dp(i,0)=sigma(1+dp(j,1) for j<i and a[i]>a[j]: now sigma 1=(no of a[j]<a[i] can be found using bit)
//sigma(dp[j,1]) can also be fund using bit while quering
//similar for dp(i,1)
//while updating for index 0 (a[i]>a[j]): add the count for type 2 uptil i to maintain alternate(understand)
//similar for index 1
//index 2 gives no of elemts <=a[i]

//its hard to visualize get the intution
void solve() {
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int ans=0;
      for(int i=0;i<n;i++){
            int v1=(query(a[i]-1,2)+query(a[i]-1,0))%mod;//less //dp(i,0)
            //to find no of elements >=a[i] :query(mx,2)-query(a[i],2)
            int v2=(query(mx,2)-query(a[i],2)+query(mx,1)-query(a[i],1));//greater //dp(i,1)
            v2=(v2+mod)%mod;
            ans+=(v1+v2)%mod;
            update(a[i],0,v2);
            update(a[i],1,v1);
            update(a[i],2,1);
          ans%=mod;
      }
      cout<<ans<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      solve();
	return 0;
}
