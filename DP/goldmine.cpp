class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        for(int col=m-2;col>=0;col--){//we are not using a diff dp table
        //we are just updating the ori matrix
            for(int row=0;row<n;row++){
                int right,rightup,rightdwn;
                right=M[row][col+1];
                rightup=(row==0)?0:M[row-1][col+1];
                rightdwn=(row==n-1)?0:M[row+1][col+1];
                M[row][col]=M[row][col]+ max(right,max(rightup,rightdwn));
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,M[i][0]);
        }
        return ans;
    }
};
