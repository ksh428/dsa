#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct coder{
      int x;
      int y;
      int index;
};
int bit[100001];
bool comp(coder a,coder b){
      if(a.x==b.x){
            return a.y<b.y;
      }
      return a.x<b.x;
}
void update(int y){
      for(;y<=100000;y+=(y&(-y))){
            bit[y]++;
      }
}
int query(int y){
      int ans=0;
      for(;y>0;y-=(y&(-y))){
            ans+=bit[y];
      }
      return ans;
}
void solve() {
      int n;
      cin>>n;
      coder a[n];
      for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y;
            a[i].index=i;
      }
      sort(a,a+n,comp);
      //bit[i] represents how many coders have smaller y than a[i].y
      int ans[n];
      for(int i=0;i<n;){
            //handle case where both x and y re equal
            int j=i;
            while(j<n and a[i].x==a[j].x and a[i].y==a[j].y) j++;
            for(int k=i;k<j;k++){
                  ans[a[k].index]=query(a[k].y);
            }
            for(int k=i;k<j;k++){
                  update(a[k].y);
            }
            i=j;
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
