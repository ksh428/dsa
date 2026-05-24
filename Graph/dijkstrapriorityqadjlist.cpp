

#include <bits/stdc++.h>

#define inf INT_MAX
using namespace std;

vector<pair<int,int> >adj[1001];



int main()
{
    int n,m,a,b,w;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});

    }
    //vector<int>vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq; //for min heap
    vector<int>dist(n+1,inf);
    pq.push({0,1}); //weight,node
    dist[1]=0;
    while(!pq.empty()){
        int curr=pq.top().second;
        int curr_d=pq.top().first;
        pq.pop();
        for(auto edge:adj[curr]){
            if(curr_d+edge.second<dist[edge.first]){
                dist[edge.first]=curr_d+edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }

    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }



}
