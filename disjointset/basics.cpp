

#include <bits/stdc++.h>

using namespace std;

int parent[10000];
int rank[10000];

void makeset(){
    //let there be n nodes
    for(int i=1;i<=n;i++){
        rank[i]=0;
        parent[i]=i;
    }
}
int findparent(int node){
    if(node==parent[node]) return node;
    return parent[node] =findparent(parent[node]);
}

void union(int u,int v){
    u=findparent(u);
    v=findparent(v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[u]>rank[v]) parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++;
    }

}

int main()
{
    makeset();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        union(u,v);
    }
    int w,y;
    cin>>w>>y;
    if(parent[w]==parent[y]) cout<<"same comp";
    else cout<<"diff comp";

}

