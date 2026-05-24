

#include<bits/stdc++.h>
using namespace std;
int findmin(int a[],int n)
{
	/*int min=0;
	for(int i:a)
	{
	if(i<min */
	if(n==1)
	return a[0];
     return min(a[n-1],findmin(a,n-1));
	
	
	
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=findmin(a,n);
	cout<<ans;
}
