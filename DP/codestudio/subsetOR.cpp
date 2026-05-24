
int solve(vector<int>&a,int x,int i,int n,int curror,vector<vector<int>>&dp){
    if(i>=n){
        if(curror==x) return 0;
        else return 1e9;
    }
    if(dp[i][curror]!=-1) return dp[i][curror];
    int op1=solve(a,x,i+1,n,curror,dp);
    int op2=1+solve(a,x,i+1,n,curror|a[i],dp);
    return dp[i][curror]=min(op1,op2);
}
//dp(i,j): min size subset with first i elements and or j
int subsetOR(vector<int> &a) {
    int n=a.size();
    int x=0;
    for(int it:a) x|=it;
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    return solve(a,x,0,n,0,dp);
}
//bottom up
