4class Solution {
public:
    #define ll long long
    int dfs(int s,vector<vector<int>>&adj,vector<int>&size){
        int ans=1;
        for(int x:adj[s]){
            ans+=dfs(x,adj,size);
        }
        return size[s]=ans;
    }
    int countHighestScoreNodes(vector<int>& p) {
        int n=p.size();
        vector<int>size(n,0);
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[p[i]].push_back(i);
        }
        dfs(0,adj,size);
        ll c=0,maxv=0;
        for(int i=0;i<n;i++){
            ll prd=1;
            prd=max(1,n-size[i]);
            for(int x:adj[i]){
                prd=prd*size[x];
            }
            if(prd>maxv){
                maxv=prd;
                c=1;
            }else if(prd==maxv){
                c++;
            }
        }
         return c;
    }

};
