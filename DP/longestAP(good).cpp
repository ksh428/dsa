class Solution{
public:
    int lengthOfLongestAP(int a[], int n) {
        if(n<=2) return n;
        int maxlen=2;
        int dp[n][n];  //dp(i,j):lap with first 2 nos a[i] and a[j];
        for(int i=0;i<n;i++) dp[i][n-1]=2;
        for(int j=n-1;j>=1;j--){
            int i=j-1;int k=j+1;
            while(i>=0 and k<=n-1){
                if(a[i]+a[k]<2*a[j]) k++;
                else if(a[i]+a[k]>2*a[j]){
                    dp[i][j]=2;//imp
                    i--;
                }else{
                    dp[i][j]=1+dp[j][k];
                    maxlen=max(maxlen,dp[i][j]);
                    i--;k++;
                }
            }
            while(i>=0){
                dp[i][j]=2;
                i--;
            }
        }
        return maxlen;
    }
};
