#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
vector<int>adj[100001];
int vis[100001];
int lvl[100001];


void bfs(int s){
      queue<int>q;
      q.push(s);
      vis[s]=1;
      int l=0;
      lvl[0]=1;
      while(!q.empty()){
            int c=0;
            l++;
            int n=q.size();
            while(n--){
                  int curr=q.front();
                  q.pop();
                  for(int j:adj[curr]){
                        if(!vis[j]) {
                              c++;
                              vis[j]=1;
                              q.push(j);
                        }
                  }
            }
            lvl[l]=c;
      }
}
//other method is  to use dist array
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	while(m--){
	      int u,v;
	      cin>>u>>v;
	      adj[u].push_back(v);
	      adj[v].push_back(u);
	}
	int q;
	cin>>q;
	while(q--){
	      int src,k;
	      cin>>src>>k;
	      for(int i=0;i<=n;i++) vis[i]=0,lvl[i]=0;
	      bfs(src);
	      cout<<lvl[k]<<endl;
	}
}
