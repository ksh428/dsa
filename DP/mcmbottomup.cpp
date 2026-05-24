
#include <bits/stdc++.h>
using namespace std;


int MatrixChainOrder(int p[], int n)
{
    int dp[n][n];
    //dp(i,j) min cost to multiply from length i to j
    for(int i=0;i<n;i++){ ///len 1 done
        dp[i][i]=0;
    }
    for(int len=2;len<n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){ //multiply the kth matrix at last
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    return dp[0][n-1];


}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}
