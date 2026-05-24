class Solution {
    //I read the qs wrong: there is no mention of no of houses
public:
    #define ll long long
    #define mod 1000000007

    int countHousePlacements(int n) {
        ll dp[n+1];//dp(i): no of ways to place houses in first i plots
        dp[0]=1;//empty
        dp[1]=2;//base case// dont skip it else it will fail
        for(int i=2;i<=n;i++){
            ll skip=dp[i-1];
            ll use=dp[i-2];
            dp[i]=(skip+use)%mod;
        }

        return (dp[n]*dp[n])%mod;


    }
};
