class Solution {
public:
    int m,n;
    int dp[71][71][71];
    // max no of cherries collected when both move from row i and rob1 from j1 and rob2 from j2 to last row
    int solve(vector<vector<int>>&a,int i,int j1,int j2){
        if(j1<0 or j1>=n or j2>=n or j2<0) return -1e8;
        if(i==m-1){
            if(j1==j2){
                return a[i][j1];
            }else return a[i][j1]+a[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        int val;
        if(j1==j2) val=a[i][j1];
        else val=a[i][j1]+a[i][j2];
        for(int k=-1;k<=1;k++){
            for(int r=-1;r<=1;r++){
                ans=max(ans,solve(a,i+1,j1+k,j2+r));
            }
        }
        return dp[i][j1][j2]=ans+val;
    }
    int cherryPickup(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        m=a.size();
        n=a[0].size();
        return solve(a,0,0,n-1);

    }
};
