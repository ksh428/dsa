
#include <bits/stdc++.h>

using namespace std;
vector<int>adj[1001];
vector<bool>vis[1001];
void dfs(int curr){
    vis[curr]=1;
    for(int j:adj[curr]){
        if(!vis[j]) dfs(j);
    }
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            c++;
        }
    }
    cout<<c;

}

