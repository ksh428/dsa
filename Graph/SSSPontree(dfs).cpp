#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1001];
int vis[1001],dis[1001];

void dfs(int node,int d){
    vis[node]=1;
    dis[node]=d;
    for(int j:adj[node]){
        if(!vis[j]){
            dfs(j,dis[node]+1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int u,v,q;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
}
