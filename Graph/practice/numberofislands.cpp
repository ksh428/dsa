//no. of islands leetcode  https://leetcode.com/problems/number-of-islands/
class Solution {
    void markisland(vector<vector<char>> &mat,int x,int y,int r,int c){
        if(x<0 || y<0 || x>=r || y>=c || mat[x][y]!='1') return;
        mat[x][y]='2';
        markisland(mat,x-1,y,r,c);
        markisland(mat,x+1,y,r,c);
        markisland(mat,x,y-1,r,c);
        markisland(mat,x,y+1,r,c);

    }
public:
    int numIslands(vector<vector<char>>& grid) {//given
        int nrows=grid.size();//for a 2d vector .size() gives no of rows
        if(nrows==0) return 0;
        int cols=grid[0].size();
        int ans=0;
        for(int i=0;i<nrows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    markisland(grid,i,j,nrows,cols);
                    ans++;
                }
            }
        }
        return ans;

    }
};

