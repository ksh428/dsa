
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve() {
      int n;
      cin>>n;
      int w[n+1];
      int s=0;
      for(int i=1;i<=n;i++) cin>>w[i],s+=w[i];
      int in[n+1]={0};
      for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            in[u]++;
            in[v]++;
      }
     priority_queue<pair<int,int>>pq;
     for(int i=1;i<=n;i++){
           if(in[i]>1){
                 pq.push({w[i],in[i]-1});//since i am starting from k=2
           }
     }
     cout<<s<<" ";
     for(int k=2;k<n;k++){
           auto curr=pq.top();
           pq.pop();
           int cw=curr.first;
           int currin=curr.second;
           s+=cw;
           cout<<s<<" ";
           currin--;
           if(currin>0) pq.push({cw,currin});

     }
     cout<<endl;
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
