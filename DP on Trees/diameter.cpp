#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int dp[200001];
int downpath[200001];

void caldownpath(int u,int p){
      int ans=0;
      for(int j:adj[u]){
            if(j!=p){
                  caldownpath(j,u);
                  ans=max(ans,1+downpath[j]);
            }
      }
      downpath[u]=ans;
}
void rec(int u,int p){
      int ans=0;
      //skip
      vector<int>v;
      int nc=0;
      for(int j:adj[u]){
            if(j!=p){
                  nc++;
                  rec(j,u);
                  v.push_back(downpath(j));
                  ans=max(ans,dp[j]);
            }
      }
      sort(v.rbegin(),v.rend());
      if(nc==0) dp[u]=0;
      else if(nc==1) dp[u]=1+v[0];
      else dp[u]=2+v[0]+v[1];
      dp[u]=max(dp[u],ans);


}
void solve(){
      caldownpath(1,0);
      rec(1,0);
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
