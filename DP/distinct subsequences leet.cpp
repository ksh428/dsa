
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        ll dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        //no of distinct subsequences of s for first i chars and t for first j chars
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};
