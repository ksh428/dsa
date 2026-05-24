// n->n/2,n/3.n-1

#include<bits/stdc++.h>
using namespace std;
int findminsteps(int n,int dp[])
{
    if(n==1)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
    {
        op1=findminsteps(n/3,dp);
    }
    if(n%2==0)
    {
        op2=findminsteps(n/2,dp);
    }
    op3=findminsteps(n-1,dp);
    int ans =min(min(op1,op2),op3)+1;
    return dp[n]=ans;
}
int main()
{
    int n;
    cin>>n;
    int dp[n]={0};
    cout<<findminsteps(n,dp);
}
