#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter size of array"<<endl;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	int c[1000001]={0};
	for(int i=0;i<1000001;i++)
	{
		c[a[i]]++;
		c[b[i]]++;
	}
	for(int i=0;i<1000001;i++)
	{
		if(c[i]>0)
		{
			while(c[i]--)
			{
				cout<<i<<endl;
			}
		}
	}
	
}
