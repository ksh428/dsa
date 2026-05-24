


#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a,b;
   cin>>a>>b;
   vector<vector<int>>dp(a+1,vector<int>(b+1,INT_MAX));
   for(int i=0;i<=a;i++){
       for(int j=0;j<=b;j++){
           if(i==j) dp[i][j]=0;
           else{
               //vertical
               for(int k=1;k<=i-1;k++){
                   dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
               }
               //horizontal
               for(int k=1;k<=j-1;k++){
                   dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
               }
           }

       }
   }
   cout<<dp[a][b];
}
