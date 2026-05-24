class Solution {
public:
    /*The key difference with the classic Dijkstra algo is, we don't maintain the global optimal distance to each node, i.e. ignore below optimization: */
    /*
    Because there could be routes which their length is shorter but pass more stops, and those routes don't necessarily constitute the best route in the end.
    */

    vector<pair<int,int>>adj[101];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;//dist,node,curr no of stops
        pq.push({0,src,0});
        vector<int>dis(n+1,INT_MAX);
        vector<int>stops(n+1,INT_MAX);
        dis[src]=0;
        stops[src]=0;
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int d=i[0];
            int u=i[1];
            int k=i[2];
            if(u==dst) return d;
            if(k==K+1) continue;
            for(auto it:adj[u]){
                int nd=d+it.second;
                int nk=k+1;
                if(nd<dis[it.first]){//normal dijkstra
                    dis[it.first]=nd;
                    stops[it.first]=nk;
                    pq.push({nd,it.first,nk});
                }else if(nk<stops[it.first]){//extra condn where takes more dist but less stops
                    stops[it.first]=nk;
                    pq.push({nd,it.first,nk});
                }
            }
        }
        return -1;


    }
};
