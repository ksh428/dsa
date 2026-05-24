/*
Q2. You have to find the shortest path between your location(0) and your office(n-1), You have given n which is the number of bus stops in nearby area, an integer k and a list routes which has k values denoting the start, end and bus no. for a stop.

Moving from start location and end location will cost you 1 unit for any bus and changing the bus from any stop will cost you 1 unit. Return the path with shortest Cost;

If it is not possible to reach the destination, return -1,

Test Case -

N = 5; k = 5;
routes = {{0, 1, 884}, {1, 2, 884}, {2, 4, 937}, {0, 3, 937}, {3, 2, 937}};

Ans = 3,
Shortest path cost 3 units
Path is 0 -> 3 -> 2 -> 4 in bus no. 937

The path - 0 -> 1 -> 2 -> 4 will cost you 4 units because at stop 2 you have to change the bus which will increase the cost by 1 unit.
*/
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve(){
      int n,k;
      cin>>n>>k;
      vector<pair<int,int>>adj[n+1];
      for(int i=0;i<k;i++){
            int u,v,b;
            cin>>u>>v>>b;
            adj[u].push_back({v,b});
      }
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;//dis,node,busno
      map<pair<int,int>,int>mp;//node,bus,dis   //alterative to dist array and is necessary
      for(auto it:adj[0]){
            pq.push({0,0,it.second});//multisource dijkstrA
            mp[{0,it.second}]=0;
      }
      int ans=INT_MAX;
      while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it[0];
            int u=it[1];
            int b=it[2];
            if(u==n-1){
                  ans=min(ans,d);
            }
            for(auto it:adj[u]){
                  int nd=d+1+(it.second!=b);
                  if(mp.find(it)==mp.end() or (mp[it]>nd)){
                        mp[it]=nd;
                        pq.push({mp[it],it.first,it.second});
                  }
            }
      }
      cout<<ans==INT_MAX?-1:ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  return 0;
}
