


#include <bits/stdc++.h>

using namespace std;
int c=0;

bool possible(int i,int j,int n,vector<vector<bool>>&visited){
    return i>=0 && j>=0 && i<n && j<n && !visited[i][j];
}
void helper(int i,int j,int n,vector<vector<int>>&grid,vector<vector<bool>>&visited){
    //base case
    if(i==n-1 && j==n-1) {
        c++;
        return;
    }
    if(!possible(i,j,n,visited)) return;
    visited[i][j]=true;
    if(i+1<n && grid[i+1][j]==0) helper(i+1,j,n,grid,visited); //D
    if(j+1 <n && grid[i][j+1]==0) helper(i,j+1,n,grid,visited);////R
    if(i-1>=0 && grid[i-1][j]==0) helper(i-1,j,n,grid,visited);//U
    if(j-1>=0 && grid[i][j-1]==0) helper(i,j-1,n,grid,visited);//L

    visited[i][j]=false;//BACKTRACK
}

int countpaths(vector<vector<int>>&grid){
    int n=grid.size();
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    helper(0,0,n,grid,visited);
    return c;

}

int main()
{
   int n;
   cin>>n;
   vector<vector<int>>grid(n,vector<int>(n,0));
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>grid[i][j];
       }
   }
   cout<<countpaths(grid)<<endl;

}
