#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	assert(1<=t&&t<=1e3);
	int count=0;
	while(t--)
	{

		int n;
		cin>>n;
		count+=n;
		assert(1<=n&&n<=1e6);

		int arr[n-1];

		for(int i=0;i<n-1;i++)
			cin>>arr[i];

		int last=0;

		for(int i=1;i<=n;i++) //store xor of all element from 1 to n as S is a permutation of 1 to n elements
		last^=i;

		for(int i=0;i<n-1;i+=2)
		last^=arr[i]; // take xor of odd elements of the given series to get the last element of S a[n]

		vector<int>v;
		v.push_back(last);
		for(int i=n-2;i>=0;i--) // iterate to get all the elements of S
		{
			last^=arr[i];
			v.push_back(last);
		}

		for(int i=n-1;i>=0;i--) //displY
		cout<<v[i]<<" ";
		cout<<endl;
	}
	assert(count<=1e7);
}
