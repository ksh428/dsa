
//GOOD


// CONSIDER A MID NODE T SO THAT BOTH PATHS FROM S1 AND S2 MEET HERE AND THEN GO BY SAME PATH TO DEST
//THIS INCLUDES ALLL THE EDGE CASES
//TO FIND THAT NODE T WE CN SIMPLY DO DIJKSTRA FROM S1 AND S2 AND INCLUDE NODE I IF IT IS REACHABLE FROM BOTH S1 AND S2
//TO CHECK WHETHER THERE IS A PATH FROM I TO DEST : JUST DO DIJKSTRA FROM DEST IN THE REVERSE GRAPH ELSE IT WILL TAKE A LOT OF TIME COMPLEITY

class Solution {
public:
    #define ll long long
    vector<pair<int,int>>adj[100001];
    vector<pair<int,int>>rev[100001];
    void dijkstra(vector<ll>&dist,int src,int f){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        pq.push({0,src}); //weight,node
        dist[src]=0;
        while(!pq.empty()){
            int curr=pq.top().second;
            int curr_d=pq.top().first;
            pq.pop();
            for(auto edge:(f==1)?rev[curr]:adj[curr]){
                if(curr_d+edge.second<dist[edge.first]){
                    dist[edge.first]=curr_d+edge.second;
                    pq.push({dist[edge.first],edge.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            rev[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>dis1(n,INT_MAX);
        vector<ll>dis2(n,INT_MAX);
        vector<ll>dis3(n,INT_MAX);
        dijkstra(dis1,src1,0);
        dijkstra(dis2,src2,0);
        dijkstra(dis3,dest,1);
        ll ans =LONG_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
        }
        cout<<INT_MAX;
        if(ans>=INT_MAX) return -1;
        return ans;

    }
};
