
class Solution {
public:
    //we dont even need a visited array as we are only considering bigger elements
    #define mod 1000000007
    int m,n;
    int dp[1001][1001];
    int dfs(int i,int j,vector<vector<int>>&a,int prev){//max increasing path starting from i,j
        if(i<0 or j<0 or i>=m or j>=n or a[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=(1+dfs(i+1,j,a,a[i][j])+dfs(i,j+1,a,a[i][j])+dfs(i-1,j,a,a[i][j])+dfs(i,j-1,a,a[i][j]))%mod;
        return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        m=a.size();
        n=a[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans+dfs(i,j,a,0))%mod;
            }
        }
        return ans;
    }
};
