#include<bits/stdc++.h> // understood!!
using namespace std;
int minstepbotup(int n)
{
    int dp[100]={0};
    dp[1]={0};
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    for(int i=2;i<=n;i++)
    {
        if(n%3==0)
            op1=dp[i/3];
        if(n%2==0)
            op2=dp[i/2];
        op3=dp[i-1];
        dp[i]=min(min(op1,op2),op3)+1;
    }

    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<minstepbotup(n);
}
