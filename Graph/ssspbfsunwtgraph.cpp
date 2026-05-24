#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int vis[10001],dis[10001];

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    dis[src]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int child:adj[curr]){
            if(!vis[child]){
                q.push(child);
                dis[child]=dis[curr]+1;
                vis[child]=1;
            }
        }
    }

}

int main(){
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;i++) adj[i].clear(),vis[i]=0;
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(1);
        cout<<dis[n]<<endl;
    }

}
