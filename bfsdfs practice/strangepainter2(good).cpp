class Solution {
public:
    bool cycle(int i,vector<int>&vis,vector<unordered_set<int>>&adj){
        vis[i]=1;
        for(int j:adj[i]){
            if(vis[j]==1) return true;
            if(vis[j]==2) continue;
            if(cycle(j,vis,adj)) return true;
        }
        vis[i]=2;
        return false;
    }

    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m=targetGrid.size();
        int n=targetGrid[0].size();
        vector<unordered_set<int>>adj(61);
        for(int i=1;i<=60;i++){
            int minx=m,miny=n,maxx=0,maxy=0;
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    if(targetGrid[x][y]==i){
                        minx=min(minx,x);
                        miny=min(miny,y);
                        maxx=max(maxx,x);
                        maxy=max(maxy,y);
                    }
                }
            }
            for(int tx=minx;tx<=maxx;tx++){
                for(int ty=miny;ty<=maxy;ty++){
                    if(targetGrid[tx][ty]!=i){
                        adj[i].insert(targetGrid[tx][ty]);
                    }
                }
            }
        }
        vector<int>vis(61,0);
        for(int i=1;i<61;i++){
            if(!vis[i]){
                if(cycle(i,vis,adj)) return false;
            }
        }
        return true;
    }
};
