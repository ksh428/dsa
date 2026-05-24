 int flag=1;
    int dp[2][W+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0) dp[flag][w]=0;
            else if(wt[i-1]<=w){
                dp[flag][w]=max(val[i - 1] +
                                 dp[1 - flag][w - wt[i - 1]],
                                dp[1-flag][w]);
            }
            else dp[flag][w]=dp[1-flag][w];
        }
        flag=1-flag;
    }
    return dp[1-flag][W];
