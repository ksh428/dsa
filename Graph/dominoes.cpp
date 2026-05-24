#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

//TOPOSORT+DFS NOT FINDING SCC
//u can oberves that finding scc does not help
//we just need to find the number of connected components
//but also make sure that if there is edge from u->v then u must come before v
//to do this just do toposort and then do normal dfs in that order and count the number of cc

int n,m;

void dfs1(int i,vector<int>adj[],int vis[],stack<int>&st){
      vis[i]=1;
      for(int j:adj[i]){
            if(!vis[j]){
                  dfs1(j,adj,vis,st);
            }
      }
      st.push(i);
}
void dfs2(int i,int vis[],vector<int>&scc,vector<int>adj[]){
      scc.push_back(i);
      vis[i]=1;
      for(int j:adj[i]){
            if(!vis[j]){
                  dfs2(j,vis,scc,adj);
            }
      }
}

void solve() {
      int c=0;

      cin>>n>>m;
      vector<int>adj[n+1];
      vector<int>rev[n+1];
      for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
      }
      stack<int>st;
      int vis[n+1]={0};
      for(int i=1;i<=n;i++){
            if(!vis[i]){
                  dfs1(i,adj,vis,st);
            }
      }
      memset(vis,0,sizeof(vis));
      while(!st.empty()){
            int curr=st.top();
            st.pop();
            if(!vis[curr]){
                  vector<int>scc;
                  dfs2(curr,vis,scc,adj);
                  c++;
            }
      }
      cout<<c<<endl;
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
