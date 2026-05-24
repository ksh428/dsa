#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve() {
      int n,m;
      cin>>n>>m;
      vector<pair<int,int>>adj[n];
      for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
      }
      int ans=0;
      int par[n];
      vector<int>dis(n,INT_MAX);
      vector<int>vis(n,0);
      dis[0]=0;
      par[0]=-1;
      int ans=0;
      for(int i=0;i<n-1;i++){
            int mini=INT_MAX,u;
            for(int v=0;v<n;v++){
                  if(vis[v]==0 and dis[v]<mini){
                        mini=dis[v];
                        u=v;
                  }
            }
            vis[u]=1;
            for(auto it:adj[u]){
                  int v=it.first;
                  int wt=it.second;
                  if(vis[v]==0 and dis[v]>wt){
                        dis[v]=wt;
                        par[v]=u;
                  }
            }
      }
      for(int x:dis){
            if(x!=INT_MAX) ans+=x;
      }

}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

///PRIMS USING PRIORITY ADJ LIST

void prims(){
    vector<int>dis(v,INT_MAX);
    vector<bool>pre(v,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    dis[1]=0;
    while(!pq.empty()){
        int currele=pq.front().second;
        int currwt=pq.front().first;
        pre[currele]=1;
        pq.pop();
        for(auto edge:adj[currele]){
            if(edge.second<dis[edge.first]){
                dis[edge.first]=edge.second;
                pq.push_back({edge.second,edge.first});
            }
        }
    }

}

int main()
{
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

	findMST(graph);
	return 0;
}

