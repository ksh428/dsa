class Solution{


	public:
	int minimumCost(int cost[], int n, int w)
	{
        vector<vector<int>>dp(n+1,vector<int>(w+1,INT_MAX));
        //dp(i,j): min cost to make wt j from first i kgs
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(j==0){
                    dp[i][j]=0;
                }else if(i==0){
                    dp[i][j]=INT_MAX;
                }else{
                    if(i<=j and cost[i-1]!=-1 and dp[i][j-i]!=INT_MAX){
                        dp[i][j]=min(dp[i-1][j],cost[i-1]+dp[i][j-i]);
                    }else dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w]!=INT_MAX?dp[n][w]:-1;
	}
};
