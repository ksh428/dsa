class Solution {
public:
    //we sort the array because we ned to find the //feel
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(dp[i]<1+dp[j] && pairs[i][0]>pairs[j][1]){
                    dp[i]=1+dp[j];
                }
            }
        }
        return dp[n-1];

    }
};
