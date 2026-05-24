class Solution {
public:
    #define ll long long int
    const int M=1e9+7;
    int N;
    int dp[1002][1002][2];

    int solve(int i,int k,int starthere){
        if(i==N) return 0;
        if(k==0) return 1;
        if(dp[i][k][starthere]!=-1) return dp[i][k][starthere];
         ll ans=0;
        ans+=solve(i+1,k,starthere);//skip  this point
        if(starthere==1){
            //start the new line
            ans+=solve(i+1,k,0);
        }else{
            //end the going line
            ans+=solve(i,k-1,1);
        }
        return dp[i][k][starthere]=ans%M;
    }

    int numberOfSets(int n, int k) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,k,1);
    }
};
