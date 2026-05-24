

#include <bits/stdc++.h>

using namespace std;
int n,m;
bool vis[1001][1001];
int dist[1001][1001];

bool isvalid(int x,int y){
    if(x<1 || x>n || y<1 || y>n) return false;
    if(vis[x][y]) return false;
    return true;
}

int dx[]={-1,0,1,0};

int dy[]={0,1,0,-1};
void dfs(int r,int c){
    vis[r][c]=true;
    for(int i=0;i<4;i++){

        if(isvalid(x+dx[i]),y+dy[i]) dfs(x+dx[i],y+dy[i]);
    }

}

void bfs(int sx,int sy){
    queue<pair<int,int> >q;
    q.push({sx,sy});
    vis[sx][sy]=1;
    dist[sx][sy]=0;
    while(!q.empty()){
        int currx=q.front().first;
        int curry=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(isvalid(currx+dx[i],curry+dy[i])){
                int newx=currx+dx[i];
                int newy=curry+dy[i];
                dist[newx][newy]=1+dist[currx][curry];
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
    }

}

int main()
{
    cin>>n>>m;
    dfs(1,1);

}
