class Solution {
public:
    pair<int,int>findpos(int curr,int n){
        int r=n-(curr-1)/n -1;
        int c=(curr-1)%n;
        if(r%2==n%2) return {r,n-1-c};
        else return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int>q;
        int steps=0;
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        q.push(1);
        vis[n-1][0]=1;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int k=1;k<=6;k++){
                    if(x+k>n*n) break;
                    pair<int,int>pos=findpos(k+x,n);
                    int r=pos.first;
                    int c=pos.second;
                    if(vis[r][c]) continue;
                    vis[r][c]=1;
                    if(board[r][c]==-1) q.push(k+x);
                    else q.push(board[r][c]);//snake or ladder is there
                }
            }
            steps++;
        }
        return -1;

    }
};
