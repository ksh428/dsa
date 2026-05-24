class Solution
{
    public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c)
    {
        vector<int>ans;
        int row_start=0,col_start=0,row_end=r-1,col_end=c-1;
        while(row_start<=row_end and col_start<=col_end){
            //row_start
            for(int col=col_start;col<=col_end;col++){
                ans.push_back(m[row_start][col]);
            }
            row_start++;
            //col_end
            for(int row=row_start;row<=row_end;row++){
                ans.push_back(m[row][col_end]);
            }
            col_end--;
            //row_end
            if(row_start<=row_end){
                for(int col=col_end;col>=col_start;col--){
                ans.push_back(m[row_end][col]);
            }
            }

            row_end--;
            //col_start
            if(col_start<=col_end){
                 for(int row=row_end;row>=row_start;row--){
                ans.push_back(m[row][col_start]);
            }
            }

            col_start++;
        }
        return ans;

    }
};
