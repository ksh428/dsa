#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct node{
      int l;
      int r;
      int pos;
      int val;
};
bool comp(node a,node b){
      if(a.val==b.val){
            return a.l>b.l;
      }
      return a.val>b.val;
}
void update(int bit[],int n,int i){
      for(;i<=n;i+=(i&(-i))){
            bit[i]++;
      }
}
int query(int bit[],int i){
      int ans=0;
      for(;i>0;i-=(i&(-i))){
            ans+=bit[i];
      }
      return ans;
}

void solve() {
      int n;
      cin>>n;
      int arr[n];

      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      int q;
      cin>>q;
      node a[n+q+1];
      for(int i=1;i<=n;i++){
            a[i].val=arr[i-1];
            a[i].r=i;
            a[i].l=0;
            a[i].pos=0;
      }
      for(int i=n+1;i<=n+q;i++){
            cin>>a[i].l>>a[i].r>>a[i].val;
            a[i].pos=i-n;
      }
      sort(a+1,a+1+n+q,comp);
      int bit[n+1];
      memset(bit,0,sizeof(bit));
      int ans[q+1];
      for(int i=1;i<=n+q;i++){
            if(a[i].pos>0){
                  int req=query(bit,a[i].r)-query(bit,a[i].l-1);
                  ans[a[i].pos]=req;


            }else{
                  update(bit,n,a[i].r);
            }
      }
      for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
