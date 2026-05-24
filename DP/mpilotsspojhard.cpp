#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
//diff=ass-cap
void initcode() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n;
int dp[1001][501];
int fun(int cap[],int ass[],int i,int diff){
      if(i==n) return 0;
      if(dp[i][diff]!=-1) return dp[i][diff];
      if(diff==0){
            return  dp[i][diff]= ass[i]+fun(cap,ass,i+1,diff+1);
      }
      else if(diff==n-i){//the diff is equal to no of remaining elements
            return  dp[i][diff]= cap[i]+fun(cap,ass,i+1,diff-1);
      }else{
            return  dp[i][diff]= min(ass[i]+fun(cap,ass,i+1,diff+1),cap[i]+fun(cap,ass,i+1,diff-1));
      }

}

void solve() {
      memset(dp,-1,sizeof(dp));
      cin>>n;
      int cap[n],ass[n];
      for(int i=0;i<n;i++){
            cin>>cap[i]>>ass[i];
      }
      cout<<fun(cap,ass,0,0)<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
