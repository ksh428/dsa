#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve() {
      string a,b;
      cin>>a>>b;
      //a->b
      int n=a.size();
      int m=b.size();
      int dp[n][m];
      //ways to transform a[0..i] to b[0..j]
    //  memset(dp,0,sizeof(dp));
      for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(i==0) dp[i][j]=0;
                  else if(j==0){
                        if(a[i]==b[j]){
                              dp[i][j]=dp[i-1][j]+1;//in this case dont take is 1 (feel)
                        }else{
                              dp[i][j]=dp[i-1][j];
                        }

                  }else{
                        //i>0,j>0
                        if(a[i]==b[j]){
                              dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//take and dont take
                        }else{
                              dp[i][j]=dp[i-1][j];

                        }
                  }

            }
      }
      cout<<dp[n-1][m-1];



}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
