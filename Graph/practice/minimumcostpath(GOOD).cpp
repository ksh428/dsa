//dijkstra application in grid
class Solution
{
    public:
    int n;
    #define pll pair<int,pair<int,int>>
    bool ok(int x,int y,vector<vector<int>>&a){
       // int n=a.size();
        if(x<0 or y<0 or x>=n or y>=n) return 0;
        return 1;
    }

    int minimumCostPath(vector<vector<int>>& a)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
         n=a.size();
        int dist[n][n];
        int vis[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=INT_MAX;
                vis[i][j]=0;
            }
        }
        priority_queue<pll,vector<pll>,greater<pll>>pq;
       // set<pll>pq;
        pq.push({a[0][0],{0,0}});
        dist[0][0]=a[0][0];
       // vis[0][0]=1;
        while(!pq.empty()){
            int cx=pq.top().second.first;
            int cy=pq.top().second.second;
            int cd=pq.top().first;
             pq.pop();
            if(vis[cx][cy]) continue;
            vis[cx][cy]=1;

            for(int i=0;i<4;i++){
                int tx=cx+dx[i];
                int ty=cy+dy[i];
                if(ok(tx,ty,a)){
                    if(dist[cx][cy]+a[tx][ty]<dist[tx][ty]){
                        // if(dist[tx][ty]!=INT_MAX){
                        //     pq.erase(pq.find({dist[tx][ty],{tx,ty}}));
                        // }
                        dist[tx][ty]=dist[cx][cy]+a[tx][ty];
                        pq.push({dist[tx][ty],{tx,ty}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
