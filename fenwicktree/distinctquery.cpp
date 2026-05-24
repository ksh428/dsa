#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct query{
      int start;
      int end;
      int idx;
};

bool comp(query a,query b){
      return a.end<b.end;
}
void update(int i,int v,int bit[],int n){
      for(;i<=n;i+=(i&(-i))){
            bit[i]+=v;
      }
}
int queryval(int i,int bit[]){
      int ans=0;
      for(;i>0;i-=(i&(-i))){
            ans+=bit[i];
      }
      return ans;
}
//bit[i]: no of distinct elements upto index i
void solve() {
      int n;
      cin>>n;
      int a[n+1];
      for(int i=1;i<=n;i++) cin>>a[i];
      int q;
      cin>>q;
      query b[q];
      for(int i=0;i<q;i++){
            cin>>b[i].start>>b[i].end;
            b[i].idx=i;
      }
      sort(b,b+q,comp);
      int ans[q];
      int last[1000001];
      memset(last,-1,sizeof(last));
      int bit[n+1]={0};
      int j=0;
      for(int i=1;i<=n;i++){
            if(last[a[i]]!=-1){
                  update(last[a[i]],-1,bit,n);
            }else{
                  pref++;
            }
            update(i,1,bit,n);
            last[a[i]]=i;
            while(j<q and b[j].end==i){
                  ans[b[j].idx]=queryval(b[j].end,bit)-queryval(b[j].start-1,bit);
                  j++;
            }
      }
      for(int x:ans) cout<<x<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
