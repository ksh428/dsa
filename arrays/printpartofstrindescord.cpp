//print part of  string in desc order
//kshounish ->(3,7)->ksinuohsh
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	assert(t >= 1 && t <= 10000);
	while(t--)
	{
		string s;
		int n,m;
		cin>>s>>n>>m;
//		cout<<s<<" "<<n<<" "<<m<<endl;
		int len = s.length();
		assert(len >= 1 && len <= 10000);
		assert(n >= 0 && n <= m);
		assert(m >= n && n <= len);
		sort(s.begin()+n,s.begin()+m+1);
		reverse(s.begin()+n,s.begin()+m+1);
		cout<<s<<endl;
	}
	return 0;
}
