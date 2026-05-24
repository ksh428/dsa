
class Solution {
public:
    int findparent(int u, vector<int>&parent) {
        if (parent[u] == u) return u;
        return parent[u] = findparent(parent[u], parent);
    }
    void unionn(int u, int v, vector<int>&parent, vector<int>&rank)
    {
        u = findparent(u, parent);
        v = findparent(v, parent);
        if (rank[u] > rank[v]) {
            parent[v] = u;

        } else if (rank[u] < rank[v]) {
            parent[u] = v;

        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
    //SEE THE VIDEO AND NOTES
    int numberOfGoodPaths(vector<int>& a, vector<vector<int>>& e) {
        int n=a.size();
        vector<int>adj[n];
        for(auto it:e){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        vector<int>rank(n, 0);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[a[i]].push_back(i);
        }
        int ans=n;
        vector<int>active(n,0);
        for(auto it:mp){
            for(auto i:it.second){
                for(auto j:adj[i]){
                    if(active[j]){
                        unionn(i,j,parent,rank);
                    }
                }
                active[i]=1;
            }
            //now we have all the connected components and all those have values<=a[i]
            //now the ans will be how many occurences of i are there in each compinent(xc2)
            map<int,int>m1;
            for(auto i:it.second){
                int curr=findparent(i,parent);
                m1[curr]++;
            }
            for(auto it:m1){
                ans+=(it.second)*(it.second-1)/2;
            }
        }
        return ans;
    }
};
