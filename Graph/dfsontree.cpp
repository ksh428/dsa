//incase of trees we donot need to maintain the viited array

void dfs(int i,int par){
      cout<<i;
      for(int x:adj[i]){
            if(x!=par){
                  dfs(x,i);
            }
      }
}

void solve() {
      dfs(1,-1);

}

