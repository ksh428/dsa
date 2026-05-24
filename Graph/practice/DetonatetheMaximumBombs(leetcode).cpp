class Solution {
public:
    #define ll long long
    void dfs(int i,vector<int>&vis,vector<int>adj[]){
        vis[i]=1;
        for(int j:adj[i]){
            if(!vis[j]) dfs(j,vis,adj);
        }
    }
    int maximumDetonation(vector<vector<int>>& a) {
        int n=a.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x1=a[i][0],y1=a[i][1],r1=a[i][2];
                int x2=a[j][0],y2=a[j][1],r2=a[j][2];
                ll ccsq=(ll)(1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2));
                ll rsq=(ll)(1ll*r1*r1);//it must hit the center of other bomb to trigger it
                if(ccsq<=rsq){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            dfs(i,vis,adj);
            int c=0;
            for(int x:vis){
                if(x==1){
                    c++;
                }
            }
            ans=max(ans,c);
            for(int i=0;i<n;i++) vis[i]=0;
        }
        return ans;

    }
};
