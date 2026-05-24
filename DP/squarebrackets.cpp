#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int dp[101][101];
int fun(int o,int c,int n,bool place[]){
      if(o>n or c>n) return 0;
      if(o==n and c==n) return 1;
      if(dp[o][c]!=-1) return dp[o][c];
      if(o==c or place[o+c]){
            return dp[o][c]= fun(o+1,c,n,place);
      }else if(o==n){
            return dp[o][c]= fun(o,c+1,n,place);
      }
      else{
            return dp[o][c]= (fun(o+1,c,n,place)+fun(o,c+1,n,place))%mod;
      }
}

void solve() {
      memset(dp,-1,sizeof(dp));
      int n,k;
      cin>>n>>k;
      int a[k];
      bool place[2*n]={0};
      for(int i=0;i<k;i++){
            cin>>a[i];
            place[a[i]-1]=1;
      }
      cout<<fun(0,0,n,place)<<endl;
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
