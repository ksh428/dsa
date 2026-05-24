/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/
//similar to knapsack 01
//space o(nm)  ...
#include<bits/stdc++.h>
using namespace std;
bool ispossible(int a[],int n,int sum)
{
    bool dp[n+1][sum+1];
    //initialization
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=sum;i++) dp[0][i]=false;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
    }
    return dp[n][sum];
}
int main()
{
    int a[]={3, 34, 4, 12, 5, 2 };
    int sum=9;
    int n=sizeof(a)/sizeof(a[0]);
    if(ispossible(a,n,sum)) cout<<"yes";
    else cout<<"no"<<endl;

}
