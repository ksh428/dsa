#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int costincdp(int h[],int n)
{
    int dp[n+1]={0};
    int op1,op2;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        op1=abs(h[i]-h[i-1])+dp[i-1];
        op2=(i==2)?inf:abs(h[i]-h[i-2])+dp[i-2];
        dp[i]=min(op1,op2);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>h[n+1]; // for 1 based indexing
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int ans=costincdp(h,n);
    cout<<ans;
}
