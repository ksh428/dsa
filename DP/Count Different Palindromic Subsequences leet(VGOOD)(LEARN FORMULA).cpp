class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int countPalindromicSubsequences(string s) {
        int n=s.size();
     vector<vector<ll>>dp(n,vector<ll>(n));
        int next[n];
        int prev[n];
        map<char,int>m;
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()) prev[i]=-1;
            else prev[i]=m[s[i]];
            m[s[i]]=i;
        }
        m.clear();
        for(int i=n-1;i>=0;i--){
            if(m.find(s[i])==m.end()) next[i]=-1;
            else next[i]=m[s[i]];
            m[s[i]]=i;
        }
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                int j=i+l-1;
                if(l==2){
                    dp[i][j]=2;
                }else{
                    if(s[i]!=s[j]){
                        dp[i][j]=(dp[i+1][j]%mod+dp[i][j-1]%mod-dp[i+1][j-1]+mod)%mod;
                    }else{
                        int nis=next[i];
                        int pie=prev[j];
                        if(nis>pie){
                            dp[i][j]=((2*dp[i+1][j-1])%mod+2)%mod;
                        }else if(nis==pie){
                            dp[i][j]=((2*dp[i+1][j-1])%mod+1)%mod;
                        }else{
                            dp[i][j]=((2*dp[i+1][j-1])%mod-(dp[nis+1][pie-1])%mod+mod)%mod;
                        }
                    }
                }
            }
        }
        return dp[0][n-1]%mod;
    }
};
