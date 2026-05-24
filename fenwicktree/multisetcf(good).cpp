#include<bits/stdc++.h>
//#define ll long long
//#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void update(int i, int v, int bit[], int n) {
      for (; i <= n; i += (i & (-i))) {
            bit[i] += v;
      }
}
int query(int i, int bit[]) {
      int ans = 0;
      for (; i > 0; i -= (i & (-i))) {
            ans += bit[i];
      }
      return ans;
}

//BIT + BINARY SEARCH
//LL TO INT


void solve() {
      int n,q;
      cin>>n>>q;
      int bit[n+1]={0};
      for(int i=0;i<n;i++){
            int x;
            cin>>x;
            update(x,1,bit,n);
      }
      for(int i=0;i<q;i++){
            int x;
            cin>>x;
            if(x>0){
                 update(x,1,bit,n);
            }else{
                  x=abs(x);
                  int ans=-1;
                  int l=1,h=n;
                  while(l<=h){
                        int m=(l+h)/2;
                        int val=query(m,bit);
                        if(val>=x){
                              ans=m;
                              h=m-1;
                        }else l=m+1;

                  }
                  update(ans,-1,bit,n);
            }
      }
      int ans=query(n,bit);
      if(ans==0){
            cout<<0<<endl;
      }else{
             for(int i=1;i<=n;i++){
                  if(query(i,bit)>0){
                        cout<<i<<endl;
                        return;
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
