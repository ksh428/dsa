

#include <bits/stdc++.h>

using namespace std;

//go from 0,0 to right end

int c=0;

void solve(int i,int j,int n,int m,string osf){
    if(i==n-1 && j==m-1){
        cout<<osf<<endl;
        c+=1;
        return;
    }
    if(i>=n || j>=m){
        return;
    }
    solve(i,j+1,n,m,osf+'R');
    solve(i+1,j,n,m,osf+'D');
}

int main()
{
  int n,m;
  cin>>n>>m;
  solve(0,0,n,m,"");
  cout<<endl;
  cout<<c<<endl;
}

