class Solution{
public:
    int dp[201][201][2];

    int solve(string s,int i,int j,int isturu){
        if(i>j) return 0;

        if(i==j){
            //only 1 element
            if(isturu) return s[i]=='T';
            else return s[i]=='F';
        }
         if(dp[i][j][isturu]!=-1) return dp[i][j][isturu];
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int lt,lf,rt,rf;
            if(dp[i][k-1][1]==-1)  lt=solve(s,i,k-1,1);
            else lt=dp[i][k-1][1];

            if(dp[i][k-1][0]==-1) lf=solve(s,i,k-1,0);
            else lf=dp[i][k-1][0];

            if(dp[k+1][j][1]==-1)  rt=solve(s,k+1,j,1);
            else rt=dp[k+1][j][1];

            if(dp[k+1][j][0]==-1)  rf=solve(s,k+1,j,0);
            else rf=dp[k+1][j][0];


            if(s[k]=='&'){
                if(isturu){
                    ans=ans+ lt*rt;
                }else ans=ans+ lt*rf + rt*lf+ lf*rf;
            }else if(s[k]=='^'){
                if(isturu){
                    ans=ans+ lt*rf + lf*rt;
                }else{
                    ans=ans+ lt*rt + lf*rf;
                }
            }else if(s[k]=='|'){
                if(isturu){
                    ans=ans+ lt*rf + rt*lf +lt*rt;
                }else ans=ans+ lf*rf;
            }

        }
        return dp[i][j][isturu]= ans%1003;
    }
    int countWays(int n, string s){
        memset(dp,-1,sizeof(dp));
       return solve(s,0,n-1,1);
    }
};
