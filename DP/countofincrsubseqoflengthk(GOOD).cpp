#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 5000000
#define endl "\n"
using namespace std;

//normal lis inside l loop wil also work

void solve(){
      int n,k;
      cin>>n>>k;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int dp[k][n];
      memset(dp,0,sizeof(dp));
      //dp[i][j]: no of inc subseq of length i ending at j
      for(int j=0;j<n;j++) dp[0][j]=1;
      for(int l=1;l<k;l++){
            for(int i=l;i<n;i++){
                  for(int p=l-1;p<i;p++){
                        if(a[p]<a[i]){
                              dp[l][i]=(dp[l][i]+dp[l-1][p])%mod;
                        }
                  }
            }
      }

    int s=0;
    for(int i=0;i<n;i++) s=(s+dp[k-1][i])%mod;
    cout<<s;

}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
