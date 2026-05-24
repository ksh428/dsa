//GOOD
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[200001];
int dp[200001][2];

//see main copy
void rec(int src,int par){
      int f=0;
      dp[src][0]=dp[src][1]=0;
      for(int j:adj[src]){
            if(j!=par){
                  f=1;
                  rec(j,src);
            }
      }
      if(!f) return;
      vector<int>pref,suf;
      for(int j:adj[src]){
            if(j!=par){
                  pref.push_back(max(dp[j][0],dp[j][1]));
                  suf.push_back(max(dp[j][0],dp[j][1]));
            }
      }
      for(int i=1;i<pref.size();i++) pref[i]+=pref[i-1];
      for(int i=suf.size()-2;i>=0;i--) suf[i]+=suf[i+1];
      dp[src][0]=suf[0];
      int childno=0;
      for(int j:adj[src]){
            if(j==par) continue;
            //select this jth child
            int lval=(childno==0)?0:pref[childno-1];
            int rval=(childno==suf.size()-1)?0:suf[childno+1];
            dp[src][1]=max(dp[src][1],lval+rval+dp[j][0]+1);
            childno++;
      }
}
void solve() {
      int n;
      cin>>n;
      for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      rec(1,0);
      cout<<max(dp[1][1],dp[1][0]);
}
int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
