
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
bool bfs(vector<vector<int>>adj,int n,int s,int t,vector<int>&par){
      queue<int>q;
      q.push(s);
      vector<int>vis(n,0);
      par[s]=-1;
      vis[s]=1;
      while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                  if(!vis[v]){
                        q.push(v);
                        vis[v]=1;
                        par[v]=u;
                  }
            }
      }
      return vis[t]==1;
}

int fordfulkerson(vector<vector<int>>adj,int n,int s,int t){
      vector<int>par(n,0);
      int mf=0;
      while(bfs(adj,n,s,t,par)){
            int pf=INT_MAX;
            for(int v=t;v!=s;v=par[v]){
                  int u=par[v];
                  pf=min(pf,adj[u][v]);
            }
            for(int v=t;v!=s;v=par[v]){
                  int u=par[v];
                  adj[u][v]-=pf;
                  adj[v][u]+=pf;
            }
            mf+=pf;
      }
      return mf;
}

void solve() {
      int n,m;
      cin>>n>>m;
      vector<vector<int>>adj(n,vector<int>(n,0));
      for(int i=0;i<m;i++){
            int x,y,w;
            cin>>w>>y>>w;
            x--,y--;
            adj[x][y]+=w;
            adj[y][x]+=w;
            if(x==y) adj[x][y]=0;
      }
      cout<<fordfulkerson(adj,n,0,n-1);


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
