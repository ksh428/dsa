#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int maxprofit(int a[],int s,int e)
{
    if(dp[s][e]!=-) return dp[s][e];
    int y=n-(s-e);
    if(s==e) return a[s]*y;
    int l=a[s]+maxprofit(a,s+1,e,y+1);
    int r=a[r]+maxprofit(a,s,r-1,y+1);
    return dp[s][e]=max(l,r);

}
//y  for l,r ::n-(l-1)-(n-r)
//dp[l][r]=max(dp[l+1]+a[l]*y),dp[l][r-1]+a[r]*y)
int main()
{
    maxprofit(a,0,n-1);

}
