#include<bits/bits/stdc++.h>
using namespace std;
int dp[100][100];
int mcm(int a[],int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];

}
int main()
{
    memset(dp,-1,sizeof(dp));
    mcm(a,1,n-1);

}
