class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int t=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!q.empty()){
            auto curr=q.front();
            t=q.front().first;
            int cx=q.front().second.first;
            int cy=q.front().second.second;
            for(int i=0;i<4;i++){
                int tx=cx+dx[i];
                int ty=cy+dy[i];
                if(tx>=0 and tx<m and ty>=0 and ty<n and grid[tx][ty]==1){
                    grid[tx][ty]=2;
                    int nt=curr.first+1;
                    q.push({nt,{tx,ty}});
                }
            }
            q.pop();
        }
        int f=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    f=1;
                    break;
                }
            }
        }
        if(f==1) return -1;
        else return t;

    }
};
