

#include <bits/stdc++.h>

using namespace std;

int dx[]={-1,0,1,0};
int dy={0,1,0,-1};

bool valid(int x,int y){
    if(vis[x][y]!=0) return false;
    if(x>=1 and x<=n and y>=1 and y<=n) return 1;
    return 0;
}

void bfs(int sx,int sy){
    queue<pair<int,int>>q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    vis[sx][sy]=1;
    while(!q.empty()){
        int cx=q.front().first;
        int cy= q.front().second;
        for(int i=0;i<4;i++){
            if(valid(cx+dx[i],cy+dy[i])){
                q.push({cx+dx[i],cy+dy[i]});
                dis[cx+dx[i]][cy+dy[i]]=dis[cx][cy]+1;
                vis[cx+dx[i]][cy+dy[i]]=1;
            }
        }
    }
}

int main()
{

}

