//detect cycle in direct graph
#include<bits/stdc++.h>
using namespace std;

bool iscycleutil(vector<int> adj[],vector<int> visited,int curr)
{
    if(visited[curr]==true) return true;
    visited[curr]=true;
    bool flag=false;
    for(int j=0;j<adj[curr].size();j++){
        flag=iscycleutil(adj,visited,adj[curr][j]);
        if(flag==true) return true;
    }
    return false;

}

bool iscycle(int v,vector<int>adj[]){
    vector<bool>visited(v,false);
    bool flag=true;
    for(int i=0;i<v;i++){
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            flag=iscycleutil(adj,visited,adj[i][j]);
            if(flag==true) return true;
        }
        visited[i]=false;//backtrack
    }
    return false;


}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    for(in ti=0;i<e;i++){ //adj list
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    iscycle(v,adj);
}
//graph coloring approach
class Solution
{
    public:
    bool dfs(int i,vector<int>&vis,vector<int>adj[]){
        vis[i]=1;
        for(int j:adj[i]){
            if(vis[j]==2) continue;
            if(vis[j]==1) return 1;
            if(dfs(j,vis,adj)) return 1;
        }
        vis[i]=2;
        return 0;
    }
	bool isCyclic(int n, vector<int> adj[])
	{
	   	vector<int>vis(n,0);
	   	for(int i=0;i<n;i++){
	   	    if(!vis[i]){
	   	        if(dfs(i,vis,adj)) return 1;
	   	    }
	   	}
	   	return 0;
	}
};
