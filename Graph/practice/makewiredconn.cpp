

#include <bits/stdc++.h>

using namespace std;

vector<int>adj[100001];
int vis[100001];

void dfs(int curr){
    vis[curr]=1;
    for(int j:adj[curr]){
        if(!vis[j]) dfs(j);
    }
}

int main()
{
    int m,n,a,b;
    cin>>m>>n;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);c++;
        }
    }
    if(m<n-1) cout<<-1;
    else{
        int redundant=m-(n-1)-(c-1);
        if(redundant>=c-1) cout<<c-1;
        else cout<<-1;
    }

}

