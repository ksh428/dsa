class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m=maze.size();
        int n=maze[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        int sx=e[0];
        int sy=e[1];
        queue<pair<int,int>>q;
        vector<vector<int>>dis(m,vector<int>(n,-1));
         vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({sx,sy});
        dis[sx][sy]=0;
        vis[sx][sy]=1;
        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();
            if(dis[cx][cy]>0){
                if(cx==0 or cx==m-1 or cy==0 or cy==n-1){
                return dis[cx][cy];
                }
            }

            for(int i=0;i<4;i++){
                int tx=cx+dx[i];
                int ty=cy+dy[i];
                if(tx>=0 and ty>=0 and tx<m and ty<n and maze[tx][ty]=='.' and vis[tx][ty]==0){
                    q.push({tx,ty});
                    vis[tx][ty]=1;
                    dis[tx][ty]=1+dis[cx][cy];
                }
            }
        }
        return -1;
    }
};
