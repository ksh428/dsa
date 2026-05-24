
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
        int n=s.size();
        int m=p.size();
        int dp[m+1][n+1];
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m and j==n) dp[i][j]=1;
                else if(i==m){
                    dp[i][j]=0;
                }else if(j==n){
                    if(p[i]=='*'){
                        dp[i][j]=dp[i+1][j];
                    }else dp[i][j]=0;
                }else{
                    //?
                    if(p[i]=='?') dp[i][j]=dp[i+1][j+1];
                    else if(p[i]=='*'){
                        dp[i][j]=dp[i+1][j] or dp[i][j+1];//optimisation step
                    }else {
                        if(p[i]==s[j]) dp[i][j]=dp[i+1][j+1];
                        else dp[i][j]=0;
                    }
                }
            }
        }
        return dp[0][0];
    }
};
