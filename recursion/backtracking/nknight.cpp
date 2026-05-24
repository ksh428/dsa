//place n non attacking knights in nxn board
#include <bits/stdc++.h>

using namespace std;

int c=0;


bool issafe(vector<vector<bool>>&grid,int row,int col,int n){
    if(row-2>=0 && col-1>=0 && grid[row-2][col-1]) return false;
    if(row-1>=0 && col-2>=0 && grid[row-1][col-2]) return false;
    if(row-2>=0 && col+1<n && grid[row-2][col+1]) return false;
    if(row-1>=0 && col+2<n && grid[row-1][col+2]) return false;
    return true;

}

void display(vector<vector<bool>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            grid[i][j]?cout<<"K ":cout<<"."<<" ";
        }
        cout<<endl;
    }
    //cout<<"\n";
}

int ans=0;//keeps no of ways
void countNKnight(vector<vector<bool>>&grid,int cr,int cc,int n,int c){
    if(c==n){ //keeps no of knights
        ans++;
        display(grid,n);
        cout<<"\n\n";
        return;
    }
    //grid[row][col]=true;
    for(int i=cr;i<n;i++){
        for(int j=(i==cr)?cc:0;j<n;j++){
            if(issafe(grid,i,j,n)){
                grid[i][j]=true;
                countNKnight(grid,i,j+1,n,c+1);
                grid[i][j]=false;//BACKTRACK
            }
        }
    }


}

int main()
{
    int n;
    cin>>n;
    vector<vector<bool>>grid(n,vector<bool>(n,false));
    countNKnight(grid,0,0,n,0);
    cout<<ans;

}

