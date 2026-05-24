
class Solution {
public:
    int dp[5001][2];
    //prev==0 can buy else cant buy
    int solve(int i,vector<int>&a,int buy){
        if(i>=a.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            int op1=-a[i]+solve(i+1,a,0);
            int op2=solve(i+1,a,1);
            return dp[i][buy]=max(op1,op2);
        }else{
            int op1=a[i]+solve(i+2,a,1);
            int op2=solve(i+1,a,0);
            return dp[i][buy]=max(op1,op2);
        }

        return 0;
    }
    int maxProfit(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return solve(0,a,1);
    }
};
