#include<bits/stdc++.h>
using namespace std;
int static dp[100][100];
bool isPal(string s,int i,int j)
{
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
            break;
        }
        i++;j--;
    }
    return true;

}
int Partition(string s,int i,int j)
{
    if(i>=j) return 0;
    if(isPal(s,i,j)) return 0;

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        if(dp[i][j]!=-1) return dp[i][j];
        int op1=Partition(s,i,k);
        int op2=Partition(s,k+1,j);
        ans=min(ans,op1+op2+1);
        dp[i][j]=ans;
    }
    return dp[i][j];

}
int main()
{
    string str = "ababbbabbababa";

    memset(dp,-1,sizeof(dp));
    int n=str.size();
    cout << "Min cuts needed for Palindrome"
            " Partitioning is "
         << Partition(str,0,n-1);

    return 0;
}
