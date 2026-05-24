#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
lli A , B , C , K;

lli F(lli x)
{
	return A * x * x + B * x + C;
}

int BSearch()
{
	if(C >= K) return 0;

	int L = 1;
	int H = ceil(sqrt(K));

	while(L <= H)
	{
		int mid = (L + H) / 2;
		lli x = F(mid);
		lli y = F(mid - 1);

		if(x >= K && y < K)
		return mid;

		if(x < K) L = mid + 1;
		else	  H = mid - 1;
	}
}

int main()
{
	lli t;
	cin>>t;
	while(t--)
	{
		cin>>A>>B>>C>>K;
		cout<<BSearch()<<endl;
	}
}
