nclude<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len=str.length();
		string vowel="aeiouAEIOU"; // note
		int count=0;
		for(int i=0;i<len;i++)
			for(int j=0;j<10;j++)
				if(str[i]==vowel[j])
				{
					count++;break;
				}
		cout<<count<<"\n";
	}
	return 0;
}
