// A simple C++ Program to count all subarrays having
// XOR of elements as given value m
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long subarrayXor(int a[], int n, int m)
{
      ll c=0;
      unordered_map<int,int>mp;
      ll cz=0;
      for(int i=0;i<n;i++){
            cz^=a[i];
            if(cz==m) c++;
            if(mp.find(cz^m)!=mp.end()){
                  c+=mp[cz^m];
            }
            mp[cz]++;
      }
      return c;

}

// Driver program to test above function
int main()
{
	int arr[] =  {5, 6, 7, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 6;

	cout << "Number of subarrays having given XOR is "
		<< subarrayXor(arr, n, m);
	return 0;
}

