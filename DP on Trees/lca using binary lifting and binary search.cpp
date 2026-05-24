#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int dp[200001][20];
int lvl[200001];
void dfs(int u,int p){
      dp[u][0]=p;
      for(int jump=1;jump<20;jump++){
            if(dp[u][jump-1]!=-1)
            dp[u][jump]=dp[dp[u][jump-1]][jump-1];
            else dp[u][jump]=-1;
      }
      for(int j:adj[u]){
            if(j!=p) dfs(j,u);
      }
}
void dfs1(int u,int p,int l){
      lvl[u]=l;
      for(int j:adj[u]){
            if(j!=p){
                  dfs1(j,u,l+1);
            }
      }
}
int query(int u,int k){
      if(u==-1) return -1;
      if(k==0) return u;
      for(int i=20;i>=0;i--){
            if(k&(1<<i)){
                  return query(dp[u][i],k-(1<<i));
            }
      }
}
int LCA(int u,int v){
      if(lvl[u]<lvl[v]) swap(lvl[u],lvl[v]);
      u=query(u,lvl[u]-lvl[v]);
      int l=0,h=lvl[u];
      int ans=-1;
      while(l<=h){
            int m=(l+h)/2;
            if(query(u,m)==query(v,m)){
                  ans=m;
                  l=m+1;
            }else r=m-1;
      }
      return query(u,ans);
}

void solve(){
        cin >> n >> q;
        for(int i=2;i<=n;i++)
        {
            cin >> x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        dfs1(1,-1,0);
        dfs(1,-1);
        while(q--){
              int u,k;
              cin>>u>>k;
              cout<<query(u,k);
        }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
  return 0;
}
