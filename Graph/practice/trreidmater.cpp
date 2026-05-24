#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
vector<int>adj[1001];
int vis[1001];
int maxval,maxnode;

void dfs(int i,int d){
      vis[i]=1;
      if(d>maxval){
            maxval=d;
            maxnode=i;
      }
      for(int j:adj[i]){
            if(!vis[j]) dfs(j,d+1);
      }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,b;
	cin>>n;
	for(int i=1;i<n-1;i++){
	      int a,b;
	      cin>>a>>b;
	      adj[a].push_back(b);
	      adj[b].push_back(a);
	}


	dfs(1,0);
	for(int i=1;i<=n;i++) vis[i]=0;
	maxval=-1;
	dfs(maxnode,0);
	cout<<maxval;

}
