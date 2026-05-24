class Solution {
public:
    //f(i,c):max profit if i consider   prices from day i to end and c transactions left
    //if(buy)==1 we can buy
    int dp[100001][3][2];
    int solve(int i,vector<int>&a,int c,int buy){
        if(i>=a.size()) return 0;
        if(c<=0) return 0;
        if(dp[i][c][buy]!=-1) return dp[i][c][buy];
        if(buy){
            int op1=-a[i]+solve(i+1,a,c,0);
            int op2=solve(i+1,a,c,1);
            return dp[i][c][buy]=max(op1,op2);
        }else{
            int op1=a[i]+solve(i+1,a,c-1,1);
            int op2=solve(i+1,a,c,0);
            return dp[i][c][buy]=max(op1,op2);
        }


    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,a,2,1);


    }
};
