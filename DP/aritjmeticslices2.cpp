class Solution {
public:
    #define ll long long
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        //NOTE: CD can go beyond int range so use ll
        //dp(i): number of aps of size>=2 ending at i with all cds
        vector<map<ll,int>>dp(n);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll cd=(ll)a[i]-a[j];
                //int prev=dp[j].count(cd)>0?dp[j][cd]:0;
                int prev=dp[j][cd];
                ans+=prev;
                dp[i][cd]+=prev+1;
            }
        }
        return ans;

    }
};
