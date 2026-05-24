#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

//sum l to r
void update(int i,int v,int bit[],int n){
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
      int a[n+1],bit[n+1]={0};
      for(int i=1;i<=n;i++){
            cin>>a[i];
            update(i,a[i],bit,n);
      }
      cout<<"sumof first 5 "<<query(5,bit)<<endl;
      cout<<"sum from 2 to 6 "<<query(6,bit)-query(1,bit);
}


int32_t main() {
	initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
