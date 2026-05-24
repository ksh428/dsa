#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int dp[1000001];
//winning or losing state is independent of player

void solve() {
     // pre();
      int k,l,m;
      cin>>k>>l>>m;
      int a[m];
      for(int i=0;i<m;i++) cin>>a[i];
      //dp(i): for i coins if its winning state 1 else 0
      dp[1]=1;
      dp[l]=1;
      dp[k]=1;
      for(int i=2;i<1000001;i++){
            dp[i]=(dp[i-1] and (i-k>=0?dp[i-k]:1) and (i-l>=0?dp[i-l]:1));
            dp[i]=!(dp[i]);
      }
      string ans="";
      for(int x:a){
            if(dp[x]) ans+='A';
            else ans+='B';
      }
      cout<<ans<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
