
#include <bits/stdc++.h>

#define inf INT_MAX
using namespace std;
int n;
vector<pair<int,int> >adj[1001];
int par[1000001];
int vis[1000001];

bool dijkstra(int s,int t){
     priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq; //for min heap
    vector<int>dist(n+1,inf);
     pq.push({0,s}); //weight,node
    dist[s]=0;
    par[s]=-1;
    while(!pq.empty()){
        int curr=pq.top().second;
        if(curr==t) return true;
        vis[curr]=1;
        int curr_d=pq.top().first;
        pq.pop();
        for(auto edge:adj[curr]){
            if(vis[edge.first]==0 && curr_d+edge.second<dist[edge.first]){
                dist[edge.first]=curr_d+edge.second;
                pq.push({dist[edge.first],edge.first});
                par[edge.first]=curr;
            }
        }

    }
    return false;

}

int main(){
     int m,a,b,w;
     vector<int>path;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});

    }
   if(dijkstra(1,n)){
       //print path
       for(int i=n;i!=-1;i=par[i]){
           path.push_back(i);

       }
       for(int i=path.size()-1;i>0;i--){
           cout<<path[i]<<" ";
       }
       cout<<path[0]<<endl;
   }else cout<<-1<<endl;
}
