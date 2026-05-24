
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<int>>&a,int row,int col,int color){
        a[row][col]=-color;
        int c=0;
        for(int i=0;i<4;i++){
            int tr=row+dx[i];
            int tc=col+dy[i];
            if(tr<0 or tc<0 or tr>=a.size() or tc>=a[0].size() or abs(a[tr][tc])!=color){
                continue;
            }
            c++;
            if(a[tr][tc]==color){
                dfs(a,tr,tc,color);
            }
        }
        if(c==4) a[row][col]=color;//not a border
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& a, int row, int col, int color) {
        int m=a.size();
        int n=a[0].size();
        dfs(a,row,col,a[row][col]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<0){
                    a[i][j]=color;
                }
            }
        }
        return a;
    }
};
