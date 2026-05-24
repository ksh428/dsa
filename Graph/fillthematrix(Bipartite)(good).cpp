
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
//  THE QS IS REDUCED TO MODIFIED FORM OF FIND BIPARTITE GRAPH IN MULTI CONNECTED GRAPH

// 1 BFS DOES THE JOB 1 CC
bool bfs(vector<vector<int>>&adj,vector<int>&col,int i,map<pair<int,int>,int>&type){
      queue<int>q;
      q.push(i);
      col[i]=1;
      while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int j:adj[curr]){
                  int c=type[{min(curr,j),max(curr,j)}];
                  if(col[j]==-1){
                        if(c==0){//MUST BE SAME
                              col[j]=col[curr];
                        }else{
                              col[j]=1-col[curr];//MUST BE DIFF
                        }
                        q.push(j);
                  }else if(abs(col[j]-col[curr])!=c) return false;//if colorings done till now does not match input given
            }
      }
      return 1;
}

bool bipartite(vector<vector<int>>&adj,int n,map<pair<int,int>,int>&type){
      vector<int>col(n+1,-1);
      for(int i=1;i<=n;i++){
            if(col[i]==-1){//do this as graph can be multicc
                  if(!bfs(adj,col,i,type)) return false;
            }
      }
      return true;
}

void solve() {
      int n,q;
      cin>>n>>q;
      vector<vector<int>>adj(n+1);
      map<pair<int,int>,int>type;
      int f=0;
      while(q--){
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(type.find({min(a,b),max(a,b)})!=type.end()){
                  if(type[{min(a,b),max(a,b)}]!=c){
                        f=1;
                  }
            }else{
                  type[{min(a,b),max(a,b)}]=c;
            }
      }
      if(f){
            cout<<"no"<<endl;
            return;
      }
      f=bipartite(adj,n,type);
      if(!f){
            cout<<"no"<<endl;
      }else cout<<"yes"<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
