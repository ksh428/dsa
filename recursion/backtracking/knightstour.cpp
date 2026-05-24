

#include <bits/stdc++.h>

using namespace std;

void display(vector<vector<int>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool issafe(vector<vector<int>>&grid,int n,int i,int j,int c,vector<vector<bool>>&visited){
    return i>=0 && j>=0 && i<n && j<n && visited[i][j]==false;
}


void knightstour(vector<vector<int>>&grid,int n,int i,int j,int c,vector<vector<bool>>&visited){
    if(c==n*n-1){
        //valid path
        grid[i][j]=c;
        display(grid,n);
        cout<<endl;
        cout<<endl;
        return;
    }
    if(c>=n*n) return;
    int dx[8]={-2,-2,-1,-1,2,2,1,1};
    int dy[8]={1,-1,2,-2,1,-1,2,-2};
    visited[i][j]=true;
    grid[i][j]=c;
    for(int k=0;k<8;k++){
        if(issafe(grid,n,i+dx[k],j+dy[k],c,visited)){

            knightstour(grid,n,i+dx[k],j+dy[k],c+1,visited);
        }

    }
    visited[i][j]=false; //backtrack


}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,-1));
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    knightstour(grid,n,0,0,0,visited);


}

