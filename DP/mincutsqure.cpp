class Solution{

	public:
	int minCut(int m, int n)
	{
	    int dp[m+1][n+1];

        for(int i = 0 ; i <= m ; i++)
        for(int j = 0 ; j <= n ; j++)
        {
            if(i==0 || j==0)  dp[i][j] = 0;

            else if(i==j) dp[i][j]=1;

            else
            {
                dp[i][j] = INT_MAX;

                for(int l = 1 ; l <= min(i,j) ; l++)
                dp[i][j] = min( dp[i][j] , 1 + min( dp[i-l][j] + dp[l][j-l] , dp[i][j-l] + dp[i-l][l] ) );
            }
        }
        return dp[m][n];
	}
};
