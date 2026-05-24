
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        //f(i,j) checks whether substr from i to j is palindrome
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans=0;
        //base case
        for(int i=0;i<n;i++) dp[i][i]=1;

        //handle len 2 cases explicitly
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]) ans++;
            }
        }
        return ans;

    }
};
