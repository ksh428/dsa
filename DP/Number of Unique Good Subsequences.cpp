
class Solution {
public:
    #define mod 1000000007
    int numberOfUniqueGoodSubsequences(string s) {
        int n=s.size();
        int dp[2][2];
        //dp(i,j):no of good subseq starting with i and enging with j
        memset(dp,0,sizeof(dp));
        for(char c:s){
            if(c=='0'){
                dp[0][0]=1; //only "0" is valid  ex in  "0100110"
                dp[1][0]=(dp[1][0]+dp[1][1])%mod;//we can add 0 to all subseq starting with 1 ending with 1 uptil now and also to all subseq starting with 1 and ending with 0
            }else{
                dp[1][1]=(dp[1][0]+dp[1][1]+1)%mod;//same as dp(1,0) but als "1" is a new subseq
                dp[0][1]=0;
            }
        }
        return (dp[0][0]+dp[0][1]+dp[1][0]+dp[1][1])%mod;
    }
};
