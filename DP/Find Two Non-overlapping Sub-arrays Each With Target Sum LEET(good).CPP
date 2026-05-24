
class Solution {
public:
int dp[100001][3];
map<int,int>m;
    int minSumOfLengths(vector<int>& a, int t) {
        int n=a.size();
        int s=0;
        m[0]=0;
        memset(dp,1e6,sizeof(dp));
        for(int i=0;i<100001;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            int d=-1;
            s+=a[i-1];
            m[s]=i;
            if(m.find(s-t)!=m.end()){
                d=m[s-t];
            }
            for(int j=1;j<=2;j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(d!=-1){
                    dp[i][j]=min(dp[i][j],dp[d][j-1]+i-d);
                }
            }
        }
        if(dp[n][2]>=1e6) return -1;
        return dp[n][2];
    }
};
