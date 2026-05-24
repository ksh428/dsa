class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod=1e9+7;
        int n=s.size();
        //dp(i):no of distinct subseq ending at i
        int dp[n+1];
        dp[0]=1;
        unordered_map<char,int>m;
        for(int i=1;i<=n;i++){
            dp[i]=2*dp[i-1]%mod;
            char ch=s[i-1];


            if(m.find(ch)!=m.end()){
                int j=m[ch];
                dp[i]=(dp[i]-dp[j-1]+mod)%mod;
            }
            m[ch]=i;
        }
        return (dp[n]-1)%mod;//-1 for non empty subseq
    }
};
