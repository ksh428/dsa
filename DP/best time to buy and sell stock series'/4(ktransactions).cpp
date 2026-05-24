//n^2 optimised
class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
       int dp[k+1][n];
        memset(dp,0,sizeof(dp));

      //dp(i,j) max profit for first j days and atmost i transactions
      for(int i=1;i<=k;i++){
            int mx=INT_MIN;
            for(int j=1;j<n;j++){
                 mx=max(mx,dp[i-1][j-1]-a[j-1]);
                int op1=dp[i][j-1];
                int op2=mx+a[j];
                dp[i][j]=max(op1,op2);
            }
      }
      //cout<<dp[k][n-1]<<endl;
        return dp[k][n-1];
    }

};
//o(nk)
class Solution {
public:
     int dp[1001][101][2];
    int solve(int i,vector<int>&a,int c,int buy){
        if(i>=a.size()) return 0;
        if(c<=0) return 0;
        if(dp[i][c][buy]!=-1) return dp[i][c][buy];
        if(buy){
            int op1=-a[i]+solve(i+1,a,c,0);
            int op2=solve(i+1,a,c,1);
            return dp[i][c][buy]=max(op1,op2);
        }else{
            int op1=a[i]+solve(i+1,a,c-1,1);
            int op2=solve(i+1,a,c,0);
            return dp[i][c][buy]=max(op1,op2);
        }


    }
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,a,k,1);
    }
};
//n^3
class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
      //dp(i,j) max profit for first j days and atmost i transactions
      for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                  int op1=dp[i][j-1];//do not sell on ith day
                  int mx=0;
                  for(int p=j-1;p>=0;p--){//bought day
                        if(a[p]<a[j]){
                              mx=max(mx,dp[i-1][p]+a[j]-a[p]);
                        }
                  }
                  int op2=mx;
                  dp[i][j]=max(op1,op2);
            }
      }
      return dp[k][n-1];
    }
};
