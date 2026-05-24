

#include <bits/stdc++.h>

#define inf INT_MAX
using namespace std;
int n;
vector<pair<int,int> >adj[1001];

bool patmorethank(int src,int k)
{
    vector<bool>path(n,false);
    path[src]=1;
    return util(src,k,path);
}
bool util(int src,int k,vector<bool>&path){
    if(k<=0) return true;
    for(auto  it:adj[src]){
        int v=*it.first;
        int w=*it.second;
        if(path[v]) continue;
        if(w>=k) return true;
        path[v]=true;
        if(util(v,k-w,path)) return true;
        path[v]=false;
    }
    return false;

}

int main()
{
    int m,a,b,w;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});

    }
    cout<<pathmorethank(0,k);
}
