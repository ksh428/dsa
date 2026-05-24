#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1e6;
int main()
{
	string a,b;cin>>a>>b;
	assert((a.size()<=mx)&&(b.size()<=mx));
	if(a.size()!=b.size()){cout<<"NO"<<endl;return 0;}
	int n=a.size();int diff[n]={0};
	for(int i=0;i<n;i++)diff[i]=b[i]-a[i];
	bool p=(diff[n-1]>=0);
	for(int i=0;i<n-1;i++)
		p&=(diff[i]>=0&&diff[i]>=diff[i+1]);
	cout<<(p?"YES":"NO")<<endl;
}
