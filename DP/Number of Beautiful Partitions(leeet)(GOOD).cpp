
class Solution {
public:
    #define mod 1000000007
    set<char>st{'2','3','5','7'};
    int ml;
    int dp[1001][1001][2];
    int solve(int i,int k,int start_here,string &s){
        if(i>=s.size()){
            if(k==0) return 1;
            else return 0;
        }
        if(k==0 and i<s.size()){
            return 0;
        }
        if(st.find(s[i])==st.end() and start_here) return 0;
        if(dp[i][k][start_here]!=-1) return dp[i][k][start_here];
        int ans;
        if(st.find(s[i])!=st.end()){
            if(start_here){
                ans=solve(i+ml-1,k,0,s);//start a new subs here and take it to atleast ml length
            }else{
                ans=solve(i+1,k,0,s);//cant start here so return the ans of the next state,note that
                //we can start from i+1 as well as i is prime
            }
        }else{
            //either start or end (minlength condition is already ensured from the prev steps)
            ans=(solve(i+1,k-1,1,s)+solve(i+1,k,0,s))%mod;
        }
        return dp[i][k][start_here]=ans;
    }
    int beautifulPartitions(string s, int k, int l) {
        ml=l;
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return solve(0,k,1,s);
    }
};
