#include<bits/stdc++.h>
using namespace std;
void bfs(int s,vector<int>adj[],bool vis[],int n){
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            if(!vis[adj[curr][i]){
                    q.push(adj[curr][i]);
                vis[adj[curr][i]]=true;

            }
        }
    }
}

int main()
{
    int n;
    int e;
    cin>>n;
    cin>>e;
    vector<int>adj[n];
    bool vis[n]={false};
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bfs(0,adj,vis,n);
}
