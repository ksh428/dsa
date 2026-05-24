// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;
int m,n;

//note: if we pass string as ref var instead of string return type it would give error in the lines temp+'d' when we pass it in dfs calls so to avoid it use string return type
string dfs(vector<vector<int> >& grid,int i,int j){
      if(i<0 or j<0 or i>=m or j>=n or grid[i][j]==0) {
           return "o";
      }
      grid[i][j]=0;
      string ans="";
      string t1='d'+dfs(grid,i+1,j);
      string t2='r'+dfs(grid,i,j+1);
      string t3='u'+dfs(grid,i-1,j);
      string t4='l'+dfs(grid,i,j-1);
      ans+=t1+t2+t3+t4;
      return ans;
}

int countDistinctIslands(vector<vector<int> >& grid)
{
      m=grid.size();n=grid[0].size();
      set<string>s;
      for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  if(grid[i][j]){
                        string temp=dfs(grid,i,j);
                        s.insert(temp);
                  }
            }
      }
      return s.size();
}

// Driver code
int main()
{
	vector<vector<int> > grid = { { 1, 1, 0, 0, 0 },
								{ 1, 1, 0, 0, 0 },
								{ 0, 0, 0, 1, 1 },
								{ 0,0 , 0, 1, 1 } };

	cout << "Number of distinct islands is "
		<< countDistinctIslands(grid);

	return 0;
}

