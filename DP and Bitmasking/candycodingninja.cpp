
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve(){
      int n;
      cin>>n;
      int a[n][n];
      for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  cin>>a[i][j];
            }
      }
      //mask->candies
      int dp[1<<n];
      memset(dp,0,sizeof(dp));
      dp[0]=1;
      for(int mask=0;mask<(1<<n)-1;mask++){
            int k=__builtin_popcount(mask);//no of students done
            for(int j=0;j<n;j++){
                  if(!(mask&(1<<j)) and a[k][j]==1){
                        dp[mask|(1<<j)]+=(dp[mask]);
                  }
            }
      }
      cout<<dp[(1<<n)-1]<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
  return 0;
}
