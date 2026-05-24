#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[200001];
int nodes[200001];//no of nodes in the subtree rooted at u
int subtreeans[200001];//ans for subtree u excluding its parent contribution
int dp[200001];//actual ans
void dfs1(int u,int p){
      int c=1;
      int v=0;
      for(int j:adj[u]){
            if(j!=p){
                  dfs1(j,u);
                  c+=nodes[j];
                  v+=subtreeans[j]+nodes[j];
            }
      }
      subtreeans[u]=v;
      nodes[u]=c;
}
void dfs2(int u,int p,int pans,int n){
     dp[u]=subtreeans[u]+pans+(n-nodes[u]);
     for(int j:adj[u]){
           if(j!=p){
                 dfs2(j,u,dp[u]-(subtreeans[j]+nodes[j]),n);
           }
     }
}

void solve(){
      int n;
      cin>>n;
      for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

      dfs1(1,0);
      dfs2(1,0,0,n);
      for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  return 0;
}
