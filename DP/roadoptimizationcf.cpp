#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

//there is no proof that greedy will always work here

void solve() {
      int n,l,k;
      cin>>n>>l>>k;
      int d[n+1],a[n];
      for(int i=0;i<n;i++) cin>>d[i];
      for(int i=0;i<n;i++) cin>>a[i];
      d[n]=l;
      vector<vector<int>>dp(n+1,vector<int>(k+1,0));
      //dp(i,j):min time for i (d[i])flags where ith flag is last and j removals
      //ans:min(dp[n][m],1<=m<=k)
      dp[0][0]=0;
      for(int i=1;i<=k;i++) dp[0][i]=INT_MAX;
      //transition:we can come from any 0<=p<i directly to i with speed s[p] and dis as d[i]-d[p]
      //so the recurrence becomes: dp[p][j-removed] where removed is no of flags skipped from p to i which is ewual to index diff of i and p
      //so for every i,j check for all such p <i and stoe the min one in dp(i,j)
      //if j=0, then it must come from i-1
      //base case can be extended like this:
      //dp[0][j]=inf, j>0
      for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                  if(j==0){
                        dp[i][j]=dp[i-1][j]+a[i-1]*(d[i]-d[i-1]);
                  }else{
                        int ans=INT_MAX;
                        for(int p=0;p<i;p++){
                              if(j-(i-p-1)>=0) ans=min(ans,dp[p][j-(i-p-1)]+a[p]*(d[i]-d[p]));
                        }
                        dp[i][j]=ans;
                  }
            }
      }
      // for(int i=0;i<=n;i++){
      //       for(int j=0;j<=k;j++){
      //             cout<<dp[i][j]<<" ";
      //       }
      //       cout<<endl;
      // }

      int ans=INT_MAX;;
      for(int i=0;i<=k;i++) ans=min(ans,dp[n][i]);

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
