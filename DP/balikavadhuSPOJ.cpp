
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve()
{
	string s1,s2;
	int K;
	cin>>s1;
	cin>>s2;
	cin>>K;
	int n=s1.size();
	int m=s2.size();
	int dp[n+1][m+1][K+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=m;j++)
        {
			for(int k=1;k<=K;k++)
            {
				if(s1[i-1]==s2[j-1])
                {
					int op1=dp[i-1][j-1][k-1]+s1[i-1];
    				if(op1 == s1[i-1] && k > 1)//good
                        //we are not getting a substr from i-1 and j-1 of length k
                        // so we cant even include this common char
        				op1 = 0;
					int op2=dp[i-1][j][k];
					int op3=dp[i][j-1][k];
					dp[i][j][k]=max(op1,max(op2,op3));
				}
    			else
				{
					int op1=dp[i-1][j][k];
					int op2=dp[i][j-1][k];
					dp[i][j][k]=max(op1,op2);
				}
			}
		}
	}

	cout<<dp[n][m][K]<<endl;

}
int32_t main() {

	int t;
	cin >> t;
	while (t--)
    {
		solve();
	}
	return 0;
}
