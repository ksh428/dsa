class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<bool>vis(v,0);
        vector<int>dist(v,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>par(v);
        par[0]=-1;
        dist[0]=0;
        pq.push({0,0});//wt,src
        int ans=0;

        while(!pq.empty()){
            int u=pq.top().second;
              vis[u]=1;

            pq.pop();
            for(auto j:adj[u]){
                int v=j[0];
                int w=j[1];
                if(!vis[v] and dist[v]>w){
                   dist[v]=w;

                   pq.push({dist[v],v});
                   par[v]=u;
                }
            }

        }
        for(int x:dist){
            if(x!=INT_MAX) ans+=x;
        }
        return ans;

    }
};
