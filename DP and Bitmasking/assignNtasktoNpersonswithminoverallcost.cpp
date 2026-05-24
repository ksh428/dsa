#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int dp[10][1024];
int mincost(int a[4][4],int n,int i,int mask){//mask represents the availabity of job ,i:person
      if(i>=n or  mask==(1<<n)-1){
            return 0;
      }
      if(dp[i][mask]!=-1) return dp[i][mask];

      int ans=INT_MAX;
      for(int j=0;j<n;j++){
            if(!(mask&(1<<j))){
                  int t=mask;
                  mask|=(1<<j);
                  ans=min(ans,a[i][j]+mincost(a,n,i+1,mask));
                  mask=t;
            }
      }
      return dp[i][mask]= ans;
}
void solve(){
      int cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
      int n=4;
     // int dp[n+1][(1<<n)];
      memset(dp,-1,sizeof(dp));
      cout<<mincost(cost,4,0,0);


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  return 0;
}

//ITERATIVR SSOLN:

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;


int mincost(int a[4][4],int n){
      int dp[(1<<n)];
      for(int i=1;i<(1<<n);i++) dp[i]=INT_MAX;
      dp[0]=0;
      for(int mask=0;mask<(1<<n)-1;mask++){
            int k=__builtin_popcount(mask);
           // cout<<k<<endl;
            for(int j=0;j<n;j++){
                  if(!(mask&(1<<j))){
                        dp[(mask|(1<<j))]=min(dp[mask|(1<<j)],dp[mask]+a[k][j]);
                  }
            }

      }
      return dp[(1<<n)-1];

}
void solve(){
      int cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
      int n=4;
      cout<<mincost(cost,4);


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  return 0;
}
