class Solution {
public:
    void dfs(vector<vector<int>>&a,int i,int j,int &eni,int &enj,int m,int n){
        eni=max(eni,i);
        enj=max(enj,j);
        a[i][j]=0;
        if(j+1<n and a[i][j+1]==1){
            dfs(a,i,j+1,eni,enj,m,n);
        }
        if(i+1<m and a[i+1][j]==1){
            dfs(a,i+1,j,eni,enj,m,n);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    int eni=i,enj=j;
                    dfs(a,i,j,eni,enj,m,n);
                    ans.push_back({i,j,eni,enj});
                }
            }
        }
        return ans;

    }
};
