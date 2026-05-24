#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findparent(int u, vector<int>&parent) {
	if (parent[u]==-1) return u;
	return findparent(parent[u], parent);
}
void unionn(int a,int b,vector<int>&parent,vector<int>&rank){
     a=findparent(a,parent);
     b=findparent(b,parent);
     if(a==b) return;
     if(rank[a]>rank[b]){
           rank[a]+=rank[b];
           parent[b]=a;
     }else{
           rank[b]+=rank[a];
           parent[a]=b;
     }
}
//rank will store the number of elements in set

void solve() {
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      int currmax=0;
      vector<int>rank(n);
      vector<int>parent(n);
      for(int i=0;i<n;i++){
            if(s[i]=='1'){
                  rank[i]=1;
                  parent[i]=-1;
                  if(i-1>=0 and s[i-1]=='1'){
                        unionn(i,i-1,parent,rank);
                  }
                  int p=findparent(i,parent);
                  currmax=max(currmax,rank[p]);
            }
      }
      while(k--){
            int no;
            cin>>no;
            if(no==1){
                  cout<<currmax<<endl;
            }else{
                  int x;
                  cin>>x;
                  x--;
                  if(s[x]=='1') continue;
                  else{
                        s[x]='1';
                        parent[x]=-1;
                        rank[x]=1;
                        if(x-1>=0 and s[x-1]=='1') unionn(x,x-1,parent,rank);
                        if(x+1<n and s[x+1]=='1') unionn(x,x+1,parent,rank);
                        int p=findparent(x,parent);
                        currmax=max(currmax,rank[p]);
                  }

            }
      }

}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
