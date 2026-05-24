

#include <bits/stdc++.h>

using namespace std;
vector<int>adj[100001];
vector<int>primes;
int dist[100001],vis[100001];

bool isvalid(int a,int b){ //checks whether only 1 digit is diff b/w 2 primes
    int c=0;
    while(a>0){ //a always < b
        if(a%10!=b%10) c++;
        a/=10;b/=10;
    }
    return c==1;
}

bool prime(int i){
    for(int j=2;j*j<=i;j++){
        if(i%j==0) return false;
    }
    return true;
}

void makegraph(){
    for(int i=1000;i<=9999;i++){
        if(prime(i)) primes.push_back(i);
    }
    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            int a=primes[i];
            int b=primes[j];
            if(isvalid(a,b)){ //add the eedge only when only 1 digit is diff in the 2 primes
                adj[a].push_back(b); adj[b].push_back(a);
            }
        }
    }
}

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    dist[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int j:adj[curr]){
            if(!vis[j]){
                vis[j]=1;
                dist[j]=dist[curr]+1;
                q.push(j);
            }
        }
    }
}
int main()
{
  int t,a,b;
  cin>>t;
  makegraph();
  while(t--){
      cin>>a>>b;
      for(int i=1000;i<=9999;i++) dist[i]=-1,vis[i]=0;
      bfs(a);
      if(dist[b]==-1) cout<<"Impossible"<<endl;
      else cout<<dist[b]<<endl;
  }

}
