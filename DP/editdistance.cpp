

#include <bits/stdc++.h>

using namespace std;


int main()
{
   string a,b;
   cin>>a;
   cin>>b;
   int n=a.size();
   int m=b.size();
   int dp[n+1][m+1];
   //base case
   dp[0][0]=0;
   for(int i=1;i<=n;i++) dp[i][0]=i;
   for(int j=1;j<=m;j++) dp[0][j]=j;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
           else{
               int op1,op2,op3;
               op1=dp[i-1][j];
               op2=dp[i][j-1];
               op3=dp[i-1][j-1];
               dp[i][j]=min(op1,min(op2,op3))+1;
           }
       }
   }
   for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";
       cout<<endl;

   }
   cout<<endl;
   cout<<dp[n][m];



}

