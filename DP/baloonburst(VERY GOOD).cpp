class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
        int b[n+2];
        b[0]=b[n+1]=1;
        for(int i=1;i<=n;i++) b[i]=a[i-1];
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
           dp[i][i]=b[i]*b[i+1]*b[i-1];
        }
        for(int length=2;length<=n;length++){
            for(int left=1;left+length<=n+1;left++){
                int right=left+length-1;
                for(int i=left;i<=right;i++){
                    dp[left][right]=max(dp[left][right],dp[left][i-1]+dp[i+1][right]+b[i]*b[left-1]*b[right+1]);
                }
            }
        }

        return dp[1][n];

    }
};
