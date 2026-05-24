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
//using graph colouring
//1: processing
//2. processed
//0. initially (untouches))
