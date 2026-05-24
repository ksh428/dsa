


#include <bits/stdc++.h>

using namespace std;
int productSubSeqCount(vector<int>a,int k){
    int n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    //dp(i,j) first i elements and prd j
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++)
        {
            if(a[i-1]<=j and a[i-1]!=0){
                dp[i][j]=dp[i-1][j/a[i-1]]+1+dp[i-1][j];
            }else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][k];
}

int main()
{
    vector<int> A;
    A.push_back(4);
    A.push_back(8);
    A.push_back(7);
    A.push_back(2);
    int k = 50;
    cout << productSubSeqCount(A, k) << endl;
}
