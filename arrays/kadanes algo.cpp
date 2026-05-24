#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0; // INT_MIN gives the minimum value that can be stored in a integer

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

//DP APPROACH
class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int n = A.size();
       int dp[n];
        dp[0] = A[0];
        int maxv = dp[0];

        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            maxv = max(maxv, dp[i]);
        }

        return maxv;
    }
};



#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(int a[],int n){
    int msf=a[0],cm=a[0];
    for(int i=1;i<n;i++){
       cm=max(a[i],cm+a[i]);
       msf=max(msf,cm);
    }
    return msf;
}

int main()
{
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;

}


