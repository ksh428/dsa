//find number of nodes for every subtree
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[200001];
void subs(int u,int par,vector<int>&dp){
      int sub=0;
      for(int j:adj[u]){
            if(j!=par){
                  subs(j,u,dp);
                  sub+=(1+dp[j]);
            }
      }
      dp[u]=sub;
}

void solve() {
      int n;
      cin>>n;
      for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            adj[x].push_back(i);
            adj[i].push_back(x);
      }
      vector<int>dp(n+1); //dp(i): no of nodes of the graph rooted at i (excluding i)

      subs(1,0,dp);
      for(int i=1;i<=n;i++) cout<<dp[i]<<" ";

}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      solve();
	return 0;
}
