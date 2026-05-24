#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
int dp[105][1<<12];

int fun(int pos,int mask,vector<string>v){
      if(mask and !(mask&(mask-1))) return 0;
      if(pos==-1 or mask==0) return 1000000;
      if(dp[pos][mask]) return dp[pos][mask];
      int mask1=0,mask2=0,c=0;
      for(int i=0;i<v.size();i++){
            if(mask&(1<<i)){
                  c++;
                  if(v[i][pos]=='0'){
                        mask1|=(1<<i);
                  }else mask2|=(1<<i);
            }
      }
      return dp[pos][mask]=min(fun(pos-1,mask,v),c+fun(pos-1,mask1,v)+fun(pos-1,mask2,v));

}


void solve() {
      memset(dp,0,sizeof(dp));

      int n;
      cin>>n;
      vector<string>v;
      for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
      }
      //for(string x:v) cout<<x<<" ";
      int l=v[0].size();
     // vector<vector<int>>dp((1<<(n+1)),vector<int>(l,INT_MAX));
      cout<<fun(l-1,(1<<n)-1,v)<<endl;

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
