
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[200001];
vector<int>vis(200001);
int f;
bool dfs(int u){//every vertext in cycle in a cc must have deg 2
      if(adj[u].size()!=2){
            //if u return here then u might not marksome nodes in this cc visited
            //which will givd wrong ans
            f=1;

      }
      vis[u]=1;
      for(int v:adj[u]){
            if(!vis[v]){
                  dfs(v);
            }
      }

}

void solve() {
      int n,m;
      cin>>n>>m;
      for(int i=1;i<=n;i++) adj[i].clear(),vis[i]=0;
      while(m--){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }
      int ans=0;
      for(int i=1;i<=n;i++){
            if(!vis[i]){
                  f=0;
                  dfs(i);
                  if(!f) ans++;
            }
      }
      cout<<ans<<endl;


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
