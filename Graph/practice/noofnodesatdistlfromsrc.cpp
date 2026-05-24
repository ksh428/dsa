#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>adj[10001];
int vis[10001],dis[10001];
vector<int>lvl(10001);

void bfs(int src){
    queue<int>q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int j:adj[curr]){
            if(!vis[j]){
                vis[j]=1;
                dis[j]=dis[curr]+1;
                q.push(j);
                lvl[dis[j]]++;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int src,l;
    cin>>src>>l;
    bfs(src);
    cout<<lvl[l]<<endl;


}
