/*
whenever the elements are not equal then make lenght =0 as it has to be consecutive //parent of lcs
*/
#include<bits/stdc++.h>
using namespace std;
int lcsubstr(char X[],char Y[],int m,int n)
{
   int dp[m+1][n+1];
   int maxval=0;
   for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0 || j==0) dp[i][j]=0;
        else if(X[i-1]==Y[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            maxval=max(maxval,dp[i][j]);
        }else{
            dp[i][j]=0;
        }
    }
   }
   return maxval;
}
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of Longest Common Substring is "
         << lcsubstr(X, Y, m, n);
    return 0;
}
