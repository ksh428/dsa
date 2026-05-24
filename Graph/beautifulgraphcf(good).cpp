#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 998244353
#define endl "\n"
using namespace std;

int n,m;
vector<int>adj[300001];
vector<int>col(300001);
vector<int>vis(300001);
vector<int>power2(300001,1);
int c0,c1;
//assume elements in a cc are coloured in a 0-1 fashion in bipartite form
//with c0 zeroes and c1 ones
//then when 0 reprenst odd no then it can have 2 values:1 and 3
//therefore tot ways for thsi cc is 2^c0+ 2^c1

bool dfs(int u){//dfs for bipartite
      vis[u]=1;
      for(int v:adj[u]){
            if(col[v]==col[u]) return 0;
            if(!vis[v]){
                  col[v]=1-col[u];
                  if(col[v]) c1++;
                  else c0++;
                  if(!dfs(v)) return 0;

            }
      }
      return 1;
}

void solve() {
      cin>>n>>m;
      for(int i=1;i<=n;i++) adj[i].clear(),col[i]=-1,vis[i]=0;
      while(m--){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }
      //solve1();
      //even if any of the component is not bipartite the ans is 0
      int ans=1;
      for(int i=1;i<=n;i++){
            c0=0,c1=1;
            col[i]=1;
            if(!vis[i]){
                  if(!dfs(i)){
                        ans=0;
                        break;
                  }else{
                        //2^co + 2^c1
                        ans=(ans*(power2[c0]+power2[c1])%mod)%mod;

                  }
            }
      }
      cout<<ans<<endl;



}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<300001;i++) power2[i]=(2*power2[i-1])%mod;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
