class Solution {
public:
    int m,n;
    bool dfs(vector<vector<char>>&b,string w,int i,int j,int idx){
        if(i<0 or j<0 or i>=m or j>=n or b[i][j]!=w[idx]) return false;
        if(idx==w.size()-1) return 1;
        char c=w[idx];
        b[i][j]='$';//to avoid visited array
        bool res=dfs(b,w,i+1,j,idx+1) || dfs(b,w,i,j+1,idx+1)
            || dfs(b,w,i-1,j,idx+1) || dfs(b,w,i,j-1,idx+1);
        b[i][j]=c;
        return res;

    }
    bool exist(vector<vector<char>>& b, string w) {
        m=b.size();
        n=b[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(b,w,i,j,0)) return true;
            }
        }
        return false;
    }
};
