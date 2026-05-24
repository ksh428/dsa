/*
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
Examples:

arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false
The array cannot be partitioned into equal sum sets.
*/
#include<bits/stdc++.h>
using namespace std;
bool findpartition(int a[],int n)
{
    int sum=0;
    for(int x:a) sum+=x;
    if(sum&1) return false;
    else{
        int newsum=sum/2;
        bool dp[n+1][newsum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int i=1;i<=newsum;i++) dp[0][i]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=newsum;j++){
                    if(a[i-1]<=j){
                        dp[i][j]=dp[i-1][j-a[j]] || dp[i-1][j];
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }

            }
        }
        return dp[n][newsum];


    }
}
int main()
{
     int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (findpartition(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}
