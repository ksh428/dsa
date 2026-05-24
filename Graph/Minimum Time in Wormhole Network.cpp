#include<bits/stdc++.h>
int pick(vector<int>vis,vector<int>dis,int n){
    int v;
    int mx=INT_MAX;
    for(int i=0;i<n;i++){
        if(vis[i]==0 and dis[i]<mx){
            mx=dis[i];
            v=i;
        }
    }
    return v;
}

int minTimeInWormholeNetwork(int n, int sx, int sy, int dx, int dy, Wormhole* wormhole)
{
    vector<int>xcor;
    vector<int>ycor;
    xcor.push_back(sx);
    ycor.push_back(sy);
    vector<int>wt;
    for(int i=0;i<n;i++){
        xcor.push_back(wormhole[i].startX);
        xcor.push_back(wormhole[i].endX);
        ycor.push_back(wormhole[i].startY);
        ycor.push_back(wormhole[i].endY);
        wt.push_back(wormhole[i].cost);
    }
    xcor.push_back(dx);
    ycor.push_back(dy);
    int sz=xcor.size();
    int adj[sz][sz];
    memset(adj,0,sizeof(adj));
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            adj[i][j]=abs(xcor[i]-xcor[j])+abs(ycor[i]-ycor[j]);
            adj[j][i]=adj[i][j];
          }
    }
    int j=0;
    for(int i=1;i<sz-1;i+=2){
        adj[i][i+1]=wt[j];
        adj[i+1][i]=wt[j];
        j++;
    }

    //dijkstra
    vector<int>dis(sz,INT_MAX);
    dis[0]=0;
    vector<int>vis(sz,0);
    for(int i=0;i<sz-1;i++){
        int u=pick(vis,dis,sz);
        vis[u]=1;
        for(int j=0;j<sz;j++){
            if(adj[u][j] and vis[j]==0 and dis[u]!=INT_MAX and dis[u]+adj[u][j]<dis[j]){
                dis[j]=dis[u]+adj[u][j];
            }
        }
    }
    return dis[sz-1];
}
