#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
vector<pair<int,int> >adj[100001];


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      int n,m,u,v;
      cin>>n>>m;
      while(m--){
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
      }
      priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
      pq.push({0,1});
      vector<int>dis(n+1,INT_MAX);
      dis[1]=0;
      while(!pq.empty()){
            int curr=pq.top().second;
            int currd=pq.top().first;
            pq.pop();
            for(auto j:adj[curr]){
                  if(currd+j.second<dis[j.first]){
                        dis[j.first]=currd+j.second;
                        pq.push({dis[j.first],j.first});
                  }
            }
      }
      cout<dis[n];
      if(dis[n]==INT_MAX) cout<<-1;
      else cout<<dis[n];

}
