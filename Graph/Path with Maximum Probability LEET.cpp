
class Solution {
public:
    //DIJKSTRA WIH MAX HEAP
    vector<pair<int,double> >adj[10001];
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& sp, int s, int end) {
        for(int i=0;i<10000;i++){
            adj[i].clear();
        }
        int m=e.size();
        for(int i=0;i<m;i++){
            adj[e[i][0]].push_back({e[i][1],sp[i]});
            adj[e[i][1]].push_back({e[i][0],sp[i]});
        }
        vector<double>mxp(n,(double)0.0);
        priority_queue<pair<double,int>>pq;
        pq.push({(double)1.0,s});
        mxp[s]=1.0;
        while(!pq.empty()){
            double currp=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto it:adj[u]){
                if(mxp[it.first]<currp*it.second){
                    mxp[it.first]=currp*it.second;
                    pq.push({mxp[it.first],it.first});
                }
            }
        }
        return mxp[end];
    }
};
