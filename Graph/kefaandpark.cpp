#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[100001];
int a[100001];
int ans=0;
int n,m;

void dfs(int i,int p,int currcons){
      if(a[i]) currcons++;
      else currcons=0;
      if(currcons>m) return;
      int nchild=0;
      for(int j:adj[i]){
            if(j!=p){
                  nchild++;
                  dfs(j,i,currcons);
            }
      }
      if(nchild==0) ans++;
}

void solve() {

      cin>>n>>m;
      for(int i=1;i<=n;i++) cin>>a[i];
      for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      dfs(1,-1,0);
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
