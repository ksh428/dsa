class Solution {
public:
    vector<pair<int,int>>adj[101];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,K+1});
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int d=i[0];
            int u=i[1];
            int k=i[2];
            if(u==dst) return d;
            if(k>0){
                for(auto j:adj[u]){ //we can push all the adj nodes without even
                    //check for min dist condition as they are restircted to k
                    // and also goal is not to find checpest global flight but with
                    //the restriction of k
                    pq.push({d+j.second,j.first,k-1});
                }
            }
        }
        return -1;


    }
};
