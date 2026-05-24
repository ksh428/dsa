
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    char c[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>c[i][j];
	        }
	    }
	    vector<vector<int>>dp(n,vector<int>(m));
	    //dp(i,j) no of trees starting at i,j
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(c[i][j]=='*') dp[i][j]=1;
	        }
	    }
	    int ans=0;
	    for(int i=n-2;i>=0;i--){
	        for(int j=m-2;j>=1;j--){
	            if(dp[i][j]==1) dp[i][j]=1+min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]));
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            ans+=dp[i][j];
	        }
	    }
	    cout<<ans<<endl;


	}
}
