
#include <bits/stdc++.h>

using namespace std;

int c=0;


bool issafe(vector<vector<bool>>&grid,int row,int col,int n){
    //col check
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]) return false;
    }
    //leftup diag
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(grid[i][j]) return false;
    }
    //rightup diag
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(grid[i][j]) return false;
    }

    return true;

}

void display(vector<vector<bool>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            grid[i][j]?cout<<"Q ":cout<<"."<<" ";
        }
        cout<<endl;
    }
}


void countNQueen(vector<vector<bool>>&grid,int curr_row,int n){
    if(curr_row==n){
        //all queens successfully placed
        c++;
        display(grid,n);
        cout<<endl;
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        //check every column whether it is safe
        if(issafe(grid,curr_row,i,n)){
            grid[curr_row][i]=true;
            countNQueen(grid,curr_row+1,n);
            grid[curr_row][i]=false;//backtrack
        }

    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<bool>>grid(n,vector<bool>(n,false));
    countNQueen(grid,0,n);
    cout<<c;

}
