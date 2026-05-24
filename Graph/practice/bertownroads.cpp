
#include <bits/stdc++.h>

using namespace std;
vector<int>adj[100001] ;
int low[100001],vis[100001],in[100001],timer;
bool hasbridge;
vector<pair<int,int> >edgelist;


void dfs(int node,int parent){
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(int child:adj[node]){
        if(child==parent) continue;
        if(vis[child]==1){
            low[node]=min(low[node],in[child]);
            if(in[node]>in[child]){
                //desendant
                edgelist.push_back({node,child});
            }
        }else {
            dfs(child,node);
            if(low[child]>in[node]){
                hasbridge=true;
                return;
            }
            edgelist.push_back({node,child});

            low[node]=min(low[node],low[child]);

        }
    }

}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    if(hasbridge) cout<<0;
    else{
        for(auto e:edgelist){
            cout<<e.first<<" "<<e.second<<endl;
        }
    }
}
