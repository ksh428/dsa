#include<bits/stdc++.h>
using namespace std

vector<int>adj[1001];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>in(n+1,0);
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
    }
    vector<int>ans(n+1,0);
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0) {
            q.push(i);
            ans[i]=1;
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int j:adj[curr]){
            in[j]--;
            if(in[j]==0){
                q.push(j);
                ans[j]=ans[curr]+1;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
