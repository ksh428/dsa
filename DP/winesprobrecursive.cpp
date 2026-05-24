#include<bits/stdc++.h>
using namespace std;
int findans(int a[],int i,int j,int y,dp)
{
    if(i>j) // base case
    return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    int op1,op2;
    op1=y*a[i]+findans(a,i+1,j,y+1);
    op2=y*a[j]+findans(a,i,j-1,y+1);
    return dp[i][j]=max(op1,op2);

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int dp[100][100]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int y=1;
    cout<<findans(a,0,n-1,y,dp)<<endl;
}
