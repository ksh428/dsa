
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[200001];
int a[100001];
int ans=0;
int n,m;

//CHECK COPY FOR NOTES
//BIPARTITE

bool bfs(int i,vector<int>&color){
      color[i]=1;
      queue<int>q;
      q.push(i);
      while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int j:adj[curr]){
                 if(color[j]==color[curr]) return false;
                 if(color[j]==-1){
                       color[j]=1-color[curr];
                       q.push(j);
                 }
            }
      }
      return true;
}

void solve() {

      cin>>n>>m;
      vector<pair<int,int>>edges;
      while(m--){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({u,v});
      }
      vector<int>color(n+1,-1);
      for(int i=1;i<=n;i++){
            if(color[i]==-1){
                  if(!bfs(i,color)){
                        cout<<"NO"<<endl;
                        return;
                  }
            }
      }
      cout<<"YES"<<endl;
      string ans="";
      for(auto it:edges){
            if(color[it.first]==0){
                  ans+='0';
            }else ans+='1';
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
