
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[200001];

int dp[200001][20];

//dp(u,i) : ans for node u when k=2^i

void pre(int u,int p){
      dp[u][0]=p;
      for(int i=1;i<20;i++){
            if(dp[u][i-1]!=-1)
                  dp[u][i]=dp[dp[u][i-1]][i-1];
            else dp[u][i]=-1;
      }
      for(int j:adj[u]){
            if(j!=p){
                  pre(j,u);
            }
      }
}
int query(int u,int k){
      if(u==-1 or k==0) return u;
      for(int i=20;i>=0;i--){
            if(k&(1<<i)){
               return query(dp[u][i],k-(1<<i));
            }
      }
}

void solve(){
        cin >> n >> q;
        for(int i=2;i<=n;i++)
        {
            cin >> x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        pre(1,-1);
        while(q--){
              int u,x;
              cin>>u>>x;
              cout<<query(u,x)<<endl;
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
