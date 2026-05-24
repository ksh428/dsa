//LEARN THE FORMULA...


class Solution{
    public:
    /*You are required to complete below method */
    const int mod=1e9+7;
    long long int  countPS(string s)
    {
       int n=s.size();
       long long int dp[n][n];

    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int l=2;l<=n;l++){
        for(int i=0;i+l<=n;i++){
            int j=i+l-1;
            if(l==2){
                dp[i][j]=(s[i]==s[j])?3:2;
            }else{
                if(s[i]==s[j]){
                    dp[i][j]=(dp[i+1][j]%mod+dp[i][j-1]%mod+1)%mod;
                }else{
                    dp[i][j]=((dp[i+1][j]%mod+dp[i][j-1]%mod)%mod-dp[i+1][j-1]%mod+mod)%mod;
                }
            }
        }
    }
       return dp[0][n-1]%mod;
    }

};
