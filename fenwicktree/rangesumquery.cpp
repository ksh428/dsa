#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void update(int val,int bit[],int i,int n){
      for(;i<=n;i+=(i&(-i))){
            bit[i]+=v;
      }
}
int query(int i,int bit[]){
      int ans=0;
      for(;i>0;i-=(i&(-i))){
            ans+=bit[i];
      }
      return ans;
}

void solve() {
      int n;
      cin>>n;
      int a[n+1];
      int bit[n+1]={0};
      for(int i=1;i<=n;i++){
            cin>>a[i];
            update(a[i],bit,i,n);
      }
      //2 types of queries
      //point upd and range sum
      int q;
      cin>>q;
      while(q--){
            int type;
            cin>>type;
            if(type==1){
                  int l,r;//0 indexed
                  cin>>l>>r;
                  cout<<query(r+1,bit)-query(l,bit)<<endl;
            }else{
                  int i,v;
                  cin>>i>>v;
                  update(-a[i+1],bit,i+1,n)
                  a[i+1]=v;
                  update(v,bit,i+1,n);
            }
      }


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
