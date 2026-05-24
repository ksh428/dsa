#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findparent(int u, vector<int>&parent) {
	if (parent[u]<0) return u;
	return parent[u]=findparent(parent[u], parent);
}
void unionn(int a,int b,vector<int>&parent,vector<int>&rank){
     a=findparent(a,parent);
     b=findparent(b,parent);
     if(rank[a]>rank[b]){
           rank[a]+=rank[b];
           parent[b]=a;
     }else{
           rank[b]+=rank[a];
           parent[a]=b;
     }
}

void solve() {
      int n;
      cin>>n;
      vector<int>parent(n,-1);
      vector<int>rank(n,1);


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
