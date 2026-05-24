
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the farthest
// smaller number in the right side
void farthest_min(int a[], int n)
{
	// To store minimum element
	// in the range i to n
	int suffix_min[n];
	suffix_min[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suffix_min[i] = min(suffix_min[i + 1], a[i]);
	}

	for (int i = 0; i < n; i++) {
		int low = i + 1, high = n - 1, ans = -1;

		while (low <= high) {
			int mid = (low + high) / 2;

			// If currnet element in the suffix_min
			// is less than a[i] then move right
			if (suffix_min[mid] < a[i]) {
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}

		// Print the required answer
		cout << ans << " ";
	}
}

// Driver code
int main()
{
	int a[] = { 3, 1, 5, 2, 4 };
	int n = sizeof(a) / sizeof(a[0]);

	farthest_min(a, n);

	return 0;
}
