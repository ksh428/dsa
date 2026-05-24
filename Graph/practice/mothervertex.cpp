//toposort

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void dfs(int i,stack<int>&st,vector<int>&vis){
      vis[i]=1;
      for(int j:adj[i]){
            if(!vis[j]) dfs(j,st,vis);
      }
      st.push(i);
}
void dfs1(int i,vector<int>&vis){
      vis[i]=1;
      for(int j:adj[i]){
            if(!vis[j]) dfs(j,vis);
      }
}

void solve() {
      stack<int>st;
      vector<int>vis(n+1,0);
      for(int i=1;i<=n;i++){
            if(!vis[i]){
                  dfs(i,st,vis);
            }
      }
      int v=st.top();
      vis.resize(n+1,0);
      dfs1(v,vis);
      int f=0;
      for(int i=1;i<=n;i++) {
            if(!vis[i]){
                  f=1;
                  break;
            }
      }
      if(f){
            cout<<"no mv present";
      }else cout<<"mv is "<<v;



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
