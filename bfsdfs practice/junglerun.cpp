
#include<bits/stdc++.h>
using namespace std;
char a[31][31];
int dist[31][31];
int vis[31][31];

int n;
int dx[]={-1,0,1,0};

int dy[]={0,1,0,-1};

bool isvalid(int x,int y){
    if(x>n || x<1 || y>n || y<1) return false;
    if(vis[x][y] || a[x][y]=='T') return false;
    return true;

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
int main(){
    cin>>n;
    int srcx,scry,endx,endy;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]=='S') srcx=i,scry=j;
            if(a[i][j]=='E') endx=i,endy=j;
        }
    }
    bfs(srcx,scry);
    cout<<dist[endx][endy];

}
