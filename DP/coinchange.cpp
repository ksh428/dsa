
//number of coins
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int inf=100000;
        int n=coins.size();
        int dp[amt+1];
        dp[0]=0;
        for(int i=1;i<=amt;i++) dp[i]=inf;
        for(int i=1;i<=amt;i++){
            int ans=inf;
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    ans=min(ans,dp[i-coins[j]]);
                }
            }
                if(ans==inf) dp[i]=inf;
                else dp[i]=1+ans;
        }
        if(dp[amt]==inf) return -1;
        else return dp[amt];

    }
};
