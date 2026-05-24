// recursive

  //TBD//

#include<bits/stdc++.h>
using namespace std;
int fib(int n,int dp[])
{
    if(n==0 || n==1)
        return n;
    if(dp[n]!=0)
        return dp[n];
   int ans;
   ans =fib(n-1,dp)+fib(n-2,dp);
    dp[n]=ans; // store the prev calc value in dp array
    return ans;

}
int main()
{
    int n;
    cin>>n;
    int dp[n]={0};
    cout<<fib(n,dp);
}
