#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[10001];

int mxn,maxd;
void dfs(int i,vector<int>&vis,int d){
      vis[i]=1;
      if(d>maxd){
            maxd=d;
            mxn=i;
      }
      for(int j:adj[i]){
            if(!vis[j]){
                  dfs(j,vis,1+d);
            }
      }

}
void solve() {
      maxd=-1;
      int n;
      cin>>n;
      for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      vector<int>vis(n+1,0);
      dfs(1,vis,0);
      maxd=-1;
      for(int i=0;i<=n;i++) vis[i]=0;
      dfs(mxn,vis,0);
      cout<<maxd;


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
