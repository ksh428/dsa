
// C++ implementation to find the smallest sum
// contiguous subarray
#include <bits/stdc++.h>

using namespace std;

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
int curr_min = arr[0] , min_so_far = arr[0];

for (int i = 0; i < n; i++)
{
curr_min = min(arr[i], arr[i] + curr_min);

min_so_far = min(min_so_far, curr_min);

//cout << curr_min << ' ' << min_so_far << endl;
}

return min_so_far;
}


// Driver program to test above
int main()
{
	int arr[] = {3, -4, 2, -3, -1, 7, -5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Smallest sum: "
		<< smallestSumSubarr(arr, n);
	return 0;
}
