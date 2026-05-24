class Solution
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(int i,vector<int>&vis,vector<int>adj[],int par){
        vis[i]=1;
        for(int j:adj[i]){
            if(!vis[j]){
                if(dfs(j,vis,adj,i)) return 1;
            }else if(j!=par) return 1;
        }
        return 0;
    }
	bool isCycle(int v, vector<int>adj[])
	{
	    vector<int>vis(v,0);
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            if(dfs(i,vis,adj,-1)) return 1;
	        }
	    }
	    return 0;
	}
};
//DSU
vector<int>dsu;
int find(int v){
      if(dsu[v]==-1) return v;
      return find(dsu[v]);

}
void union(int fromp,int top){
      dsu[fromp]=top;
}
void solve(){
      dsu.resize(n,-1);
      vector<pair<int,int>>>adj;
      for(auto it:adj){
            int fromp=find(it.first);
            int top=find(it.second);
            if(fromp==top){
                  cout<<1<<endl;
                  return;
            }
            union(fromp,top);
      }
      cout<<0<<endl;

}
//dsu optimization

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
struct node{
      int parent;
      int rank;
};
vector<node>dsu;

int find(int v){
      if(dsu[v].parent==-1) return v;
      return dsu[v].parent=find(dsu[v].parent);
}
void union(int fromp,int top){
      int fromrank=dsu[from].rank;
      int torank=dsu[top].rank;
      if(fromrank>torank){
            dsu[top].parent=fromp;
      }else if(fromrank==torank){
            dsu[fromp].parent=top;
      }else{
            dsu[fromp].parent=top;
            dsu[top].rank+=1;
      }

}

int32_t main() {
      int v,e;
      cin>>v>>e;
      vector<pair<int,int>>adj;
      while(e--){
            int a,b;
            cin>>a>>b;
            adj.push_back({a,b});
            adj.push_back({b,a});
      }
      dsu.resize(v);

      for(int i=0;i<v;i++){
            dsu[i].rank=0;
            dsu[i].parent=-1;
      }
      for(auto it:adj){
            int fromp=find(it.first);
            int top=find(it.second);
            if(fromp==top){
                  cout<<1<<endl;
                  return;
            }
            union(fromp,top);
      }


}

//DSU CANT BE USED TO DETECT CYCLE IN DIRECTED GRAPHS

