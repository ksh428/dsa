
//FEASIBLE SOLUTIONS

#include<bits/stdc++.h>
#define max 1000000
using namespace std;
vector<int>adj[200001],newadj[200001];
int vis[200001];
set<int>isconnected;


void dfs(int curr){
    vis[curr]=1;
    for(int j:adj[curr]){
        if(vis[j]==0) dfs(j);
    }
}
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    vis[1]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int j:adj[curr]){
            if(!vis[j]) {
                newadj[curr].push_back(j),newadj[j].push_back(curr);
                vis[j]=1;
                if(j==1) isconnected.insert(curr);
                if(j!=1)
                q.push(j);
            }
        }
    }
}
void newbfs(int st){
    vis[st]=1;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int j:newadj[curr]){
            if(!vis[j]){
            vis[j]=1;
            cout<<curr<<" "<<j<<endl;
            q.push(j);
            }
        }
    }
}

int main(){
  int n,m,d,a,b;
  cin>>n>>m>>d;
  for(int i=1;i<=m;i++){
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  int cc=0;
  vis[1]=1;
  for(int i=2;i<=n;i++){
      if(vis[i]==0) dfs(i),cc++;
  }
  if(d>=cc && d<=adj[1].size()) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  for(int i=1;i<=n;i++) vis[i]=0;

  for(int i=2;i<=n;i++){
      if(!vis[i]) bfs(i);
  }

  for(int i=1;i<=n;i++) vis[i]=0;
  int rem=d-cc;
  for(int j:adj[1]){
      if(rem==0) break;
      if(isconnected.find(j)==isconnected.end()){
          newadj[1].push_back(j),newadj[j].push_back(1);
          rem--;
      }
  }

  newbfs(1);



}


