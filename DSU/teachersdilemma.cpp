#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findparent(int u, vector<int>&parent) {
	if (parent[u]<0) return u;
	return findparent(parent[u], parent);
}
void unionn(int a,int b,vector<int>&parent){
      parent[a]+=parent[b];
      parent[b]=a;
}

void solve() {
      int n,m;
      cin>>n>>m;
      vector<int>parent(n+1,-1);
      for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u=findparent(u,parent);
            v=findparent(v,parent);
            if(u!=v){
                  unionn(u,v,parent);
            }
      }
      int ans=1;
      for(int i=1;i<=n;i++){
            if(parent[i]<0){
                  ans=(ans*abs(parent[i]))%mod;
            }
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

//CAN ALSO BE SOLVED NORMAL DSU
