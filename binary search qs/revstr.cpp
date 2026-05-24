#include<bits/stdc++.h>
using namespace std;
void rev(string s,int start,int end)
{
	
	if(start>=end)
	return;
	char temp;
	temp=s[start];
	s[start]=s[end];
	s[end]=temp;
	return rev(s,start+1,end-1);	
}
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	string ans=rev(s,0,n-1);
	cout<<ans;
}
