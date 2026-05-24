
class Solution {
public:
    string largestNumber(vector<int>& cost, int t) {
       string ans="";
        vector<int>dp(t+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=t;i++){
            for(int j=0;j<9;j++){
                if(cost[j]<=i){
                    dp[i]=max(dp[i],1+dp[i-cost[j]]);
                }
            }
        }
      //  cout<<dp[t];
       if(dp[t]<0) return "0";
        while(t>0){
            int pos=-1;
            for(int i=8;i>=0;i--){
                if(t>=cost[i] and (pos==-1 or dp[t-cost[i]]>dp[t-cost[pos]])){
                    pos=i;
                }
            }
            ans+=to_string(pos+1);
            t-=cost[pos];
        }
        return ans;
    }
};
