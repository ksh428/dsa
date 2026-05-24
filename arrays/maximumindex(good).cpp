
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:

    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n)
    {
       int i, j,maxDiff;

    int LMin[n];
    int RMax[n];

    LMin[0] = arr[0];
    for (i = 1; i < n; ++i)
        LMin[i] = min(arr[i], LMin[i - 1]);

    RMax[n - 1] = arr[n - 1];
    for (j = n - 2; j >= 0; --j)
        RMax[j] = max(arr[j], RMax[j + 1]);

    i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n) {
        if (LMin[i] <= RMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j = j + 1;
        }
        else
            i = i + 1;
    }

    return maxDiff;
    }
};

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];

        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;

        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;

    }
    return 0;
}   // } Driver Code Ends
