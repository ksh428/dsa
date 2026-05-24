int f=0;
 bool dfs(int src,vector<int> adj[],vector<int>vis,int n,int c,int s){//s is the original source
        if(c==n){
              //check for hc
              int f1=0;
              for(int j:adj[src]){
                    if(j==s){
                          f1=1;
                          break;
                    }
              }
              if(f1){
                    f=1;
              }
              return 1;
        }
        vis[src]=1;
        for(int j:adj[src]){
            if(!vis[j]){
                if(dfs(j,adj,vis,n,c+1,s)) return 1;
            }
        }
        vis[src]=0;
        return 0;
    }
    bool check(int n,int m,vector<vector<int>> edges)
    {
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]) {
                if(dfs(i,adj,vis,n,1,i)) return 1;
            }
        }
        if(f){
              cout<<"there exsists a hamiltonian cycle";
        }
        return 0;

    }
