class Solution{
public:
#define mod 1000000007
    long int disarrange(int N){
        long int dp[N+1]={0};

        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=N;i++){
            dp[i]=(i-1)LL*(dp[i-1]+dp[i-2]);
        }
        return dp[N]%mod;
    }
};
//GOOD
//COULDNT PRROF THE RECURRENC E
