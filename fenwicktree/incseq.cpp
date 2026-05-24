#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 5000000
#define endl "\n"
using namespace std;

int n,k;
int bit[52][200001];

int query(int i,int j){
      int ans=0;
      for(;i>0;i-=(i&(-i))){
            ans=(ans+bit[j][i])%mod;
      }
      return ans;
}
void update(int i,int val,int j){
      for(;i<=100000;i+=(i&(-i))){
            bit[j][i]=(bit[j][i]+val)%mod;
      }
}
void solve(){

      cin>>n>>k;
      if(k==1){
            cout<<n<<endl;
            return;
      }
      int a[n+1];
      for(int i=1;i<=n;i++){
            cin>>a[i];

      }
      int ans=0;
      for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                  int val=(j==1)?1:query(a[i]-1,j-1);
                  update(a[i],val,j);
                  if(j==k) ans=(ans+val)%mod;
            }
      }
      cout<<ans;

}
//DP + BIT

int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
