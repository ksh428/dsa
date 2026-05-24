#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findparent(int u, vector<int>&parent) {
	if (parent[u]==-1) return u;
	return parent[u]=findparent(parent[u], parent);
}
void  unionn(int a,int b,vector<int>&parent,vector<int>&rank){
     a=findparent(a,parent);
     b=findparent(b,parent);
     if(a==b) return;
     if(rank[a]>rank[b]){
           rank[a]+=rank[b];
           parent[b]=a;
     }else{
           rank[b]+=rank[a];
           parent[a]=b;
     }
}
//rank will store the number of elements in set

void solve() {
     int n,m;
     cin>>n>>m;
     vector<int>parent(n+1,-1);
     vector<int>rank(n+1,1);
     int ncc=n;
     int mx=1;
     while(m--){
           int u,v;
           cin>>u>>v;
           if(findparent(u,parent)==findparent(v,parent)){
                 cout<<mx<<" "<<ncc<<endl;
           }else{
                 ncc--;
                 unionn(u,v,parent,rank);
                 int p=findparent(u,parent);
                 mx=max(mx,rank[p]);
                 cout<<mx<<" "<<ncc<<endl;
           }

     }

}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
