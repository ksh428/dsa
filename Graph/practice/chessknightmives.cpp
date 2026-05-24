#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int vis[10][10];
int tx,ty;

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

bool isvalid(int x,int y){
    if(x<1 || x>8 || y<1 || y>8) return false;
    if(vis[x][y]) return false;
    return true;

}

int bfs(int sx,int sy){
    queue<pair<int,int> >q;
    q.push({sx,sy});
   // dist[sx][sy]=0;
    vis[sx][sy]=1;
    int l=0;
    if(sx==tx && sy==ty) return l;
    l++;
    while(!q.empty()){
          int n=q.size();
          while(n--){
              int cx=q.front().first;
              int cy=q.front().second;
              q.pop();
              for(int i=0;i<8;i++){
                  if(isvalid(cx+dx[i],cy+dy[i])){
                      int nx=cx+dx[i];
                      int ny=cy+dy[i];
                      //dist[nx][ny]=1+dist[cx][cy];
                      vis[nx][ny]=1;
                      q.push({nx,ny});
                      if(nx==tx && ny==ty) return l;
                  }
              }

          }
          l++;
    }

}
int getX(int a){
    return a-'a'+1;
}

int main(){
    int t,x,y;
    cin>>t;
    while(t--){
        char a,b;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                vis[i][j]=0;
            }
        }
        cin>>a>>b;
        x=getX(a);
        y=b-'0';
        cin>>a>>b;
        tx=getX(a);
        ty=b-'0';
        cout<<bfs(x,y)<<endl;


    }
}
