//NOT WORKING
class Solution
{
    public:

    //Function to find a solved Sudoku.
    bool valid(int grid[N][N],int x,int y,int po){
        for(int col=0;col<N;col++){
            if(grid[x][col]==po) return false;
        }
        for(int row=0;row<N;row++){
            if(grid[row][y]==po) return false;
        }
        int xi=x/3*3;
        int yj=y/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[xi+i][yj+j]==po) return false;
            }
        }
        return true;
    }
    bool f=false;
    void sudoku(int grid[N][N],int i,int j){
        if(i>N or j>=N) return;
        if(i==N){
            f=true;
            printGrid(grid);
            return;
        }
        int ni=0,nj=0;
        if(j==N-1){
            ni=i++;
            nj=0;
        }else{
            ni=i;
            nj=j++;
        }
        if(grid[i][j]!=0) sudoku(grid,ni,nj);
        else{
            for(int po=1;po<=9;po++){
                if(valid(grid,i,j,po)){
                    grid[i][j]=po;
                    sudoku(grid,ni,nj);
                    grid[i][j]=0;
                }
            }
        }
    }
    bool SolveSudoku(int grid[N][N])
    {

        sudoku(grid,0,0);
        return f;
    }

    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N])
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
