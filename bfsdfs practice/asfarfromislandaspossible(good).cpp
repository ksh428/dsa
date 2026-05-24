class Solution {
public:
    //multisourse bfs
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1) q.push({i,j}),vis[i][j]=1;
            }
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int l=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto curr=q.front();
                q.pop();
                int cx=curr.first;
                int cy=curr.second;
                for(int i=0;i<4;i++){
                    int tx=cx+dx[i];
                    int ty=cy+dy[i];
                    if(tx>=0 and ty>=0 and tx<n and ty<n and !vis[tx][ty] and a[tx][ty]==0){
                        vis[tx][ty]=1;
                        q.push({tx,ty});
                    }
                }
            }
            l++;
        }
        return (l<=1)?-1:l-1;

    }
};
