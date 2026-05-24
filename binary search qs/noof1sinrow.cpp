#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3][4];
		int c;
	//	vector<int>v;
	for(int i=0;i<3;i++)
	for(int j=0;j<4;j++)
	{
		cin>>a[i][j];
	
	}
	int max=0;int row;
	for(int i=0;i<3;i++)
	{
		int row=i;
		c=0;
		for(int j=0;j<4;j++)
		{
			if(a[row][j]==1)
			c++;
		}
		if(c>max)
		{max=c;
		row=i;
		}
		
	}
	cout<<max<<" "<<row;

	
}
