class Solution
{
public:
    int wordBreak(string s, vector<string> &b) {
        //code here
        set<string>st(b.begin(),b.end());
        int n=s.size();
        int dp[n+1]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] and st.find(s.substr(j,i-j))!=st.end()){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
