#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int i=0;
		while(i<n-2)
		{
			if(a[i]==1)
			{
				if(a[i+1]==0 && a[i+2]==0 && a[i+3]==0)
				{
					cout<<"YES"<<endl;
				}
				else
				cout<<"NO"<<endl;
			}
		}
		
	}
