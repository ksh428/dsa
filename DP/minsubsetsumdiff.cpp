class Solution{

	public:
	int minDifference(int a[], int n)
	{
	    // Your code goes here
	    int s=0;
        for(int i=0;i<n;i++) s+=a[i];
        bool dp[n+1][s+1]; //dp(i,j) :whether there exsist a subset with sum j from the first i elements

        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=s;i++) dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];
                }else dp[i][j]=dp[i-1][j];
            }
        }
        int ans=INT_MAX;
        for(int j=s/2;j>=0;j--){
           if(dp[n][j]) {

               ans=s-2*j;
               break;
           }
        }
        return ans;
	}
};
