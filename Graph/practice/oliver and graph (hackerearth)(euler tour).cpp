#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int p,vector<int>adj[],vector<int>&v){
      v.push_back(i);
      for(int j:adj[i]){
            if(j!=p){
                  dfs(j,i,adj,v);
            }
      }
      v.push_back(i);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n;
	vector<int>adj[n+1];
	vector<int>v;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1,adj,v);
	cin>>q;
	unordered_map<int,int>first,last;
	int i=0;
	for(auto it:v){
	      if(first.find(it)==first.end()) first[it]=i;
	      last[it]=i;
	      i++;
	}

	while(q--){
	      int a,b,c;
	      cin>>a>>b>>c;
	      if(a==0){
	            int l=first[b];
	            int r=last[b];
	            int f1=first[c];
	            int f2=last[c];
	            if(f1>=l and f2<=r){
	                  cout<<"YES"<<endl;
	            }else cout<<"NO"<<endl;
	      }else{
	            int l=first[c];
	            int r=last[c];
	            int f1=first[b];
	            int f2=last[b];
	            if(f1>=l and f2<=r){
	                  cout<<"YES"<<endl;
	            }else cout<<"NO"<<endl;
	      }
	}

}
Language: C++17
