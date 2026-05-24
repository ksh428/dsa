
class Solution {
public:

    void dfs(vector<vector<int>>&A,int i,int j,int isno,int n,int m){
        if(i>=n || i<0 || j>=m || j<0 || A[i][j]!=1) return;
        A[i][j]=isno;
        dfs(A,i-1,j,isno,n,m);
        dfs(A,i,j-1,isno,n,m);
        dfs(A,i+1,j,isno,n,m);
        dfs(A,i,j+1,isno,n,m);
    }

    int shortestBridge(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        if(n==0) return 0;
        int isno=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==1){
                    dfs(A,i,j,isno,n,m);
                    isno++;
                }
            }
        }
        vector<pair<int,int>>a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==2){
                    a.push_back({i,j});
                }else if(A[i][j]==3) b.push_back({i,j});
            }
        }
        int ans=10000;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                int tempdist=abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second)-1;
                ans=min(ans,tempdist);
            }
        }
        return ans;

    }
};
