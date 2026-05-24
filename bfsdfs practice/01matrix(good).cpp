
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        //brute force bfs:nm*nm
        //so optimize itusing multisoirse bfs
        //understand!!
        //initially push all the 0s
        //
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0) q.push({i,j});
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
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
                    if(tx>=0 and ty>=0 and tx<m and ty<n){
                        if(a[tx][ty]==1){//whenevr u encounter a 1 then update its ans and use it as virtual 0 with its current level to find neighbiuring 1s
                            ans[tx][ty]=l+1;
                            a[tx][ty]=0;
                            q.push({tx,ty});
                        }
                    }
                }
            }
            l++;
        }

        return ans;

    }
};
