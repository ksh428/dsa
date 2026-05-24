#include<bits/stdc++.h>
using namespace std;
int solve(int h[],int n,int k)
{
    vector<int>dp(n+1); // note vector declaration
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int ops;
        dp[i]=INT_MAX;
        for(int j=i-1;j>=1 &&(i-j)<=k;j--)
        {
            ops=abs(h[j]-h[i])+dp[j];
            dp[i]=min(ops,dp[i]);
        }
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>height(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>height[i];
    }
    cout<<solve(height,n,k);
    //cout<<ans<<endl;

}
