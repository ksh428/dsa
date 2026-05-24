#include <bits/stdc++.h>
using namespace std;


bool isBipartite(int v, vector<int> adj[])
{
    vector<int>col(v,-1);
    queue<pair<int,int>>q;
    for(int i=0;i<v;i++){
        if(col[i]==-1){
            q.push({0,i});
            col[i]=0;
            while(!q.empty()){
                auto p=q.front();q.pop();
                int curr=p.second;
                //int color=p.first;
                for(int j:adj[curr]){
                    if(col[j]==col[curr]) return 0;
                    else if(col[j]==-1){
                        col[j]=1-col[curr];
                        q.push({col[j],j});
                    }
                }
            }
        }
    }
    return 1;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<int>rev[n];
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        v[i]=1;
        for(int j:adj[i]){
            v[j]=1;
        }
        for(int j=0;j<n;j++){
            if(v[j]==0){
               rev[j].push_back(i);
               rev[i].push_back(j);
            }
        }
        v.clear();
    }
    if(isBipartite(n,rev)) cout<<1;
    else cout<<0;
}

