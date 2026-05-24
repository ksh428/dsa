#include<bits/stdc++.h>
using namespace std;
int mincoinchng(int coins[],int N,int T)
{
    int dp[N+1]={0};
    // we will traverse through this dp array and store the value at the array
    dp[0]=0;
    for(int i=1;i<=N;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<T;j++)
        {
            if(i-coins[j]>=0) // checks the condition for each step of the array until N
            {
                int subprob=dp[i-coins[j]]; // find the subproblems
                dp[i]=min(dp[i],subprob)+1; // store the min of the subproblems in the dp array at every index //STORING STATEMENT
            }
        }
    }
    return dp[N];


}
int main()
{
    int N,T;  //N is denomination
    cout<<"Enter denomination "<<endl;
    cin>>N;
    cout<<"ENTER no. of coins"<<endl;
    cin>>T;
    int coins[T];
    cout<<"enter coins"<<endl;
    for(int i=0;i<=T;i++)
    {
        cin>>coins[i];
    }
   int ans= mincoinchng(coins,N,T);
   cout<<ans<<endl;


}
