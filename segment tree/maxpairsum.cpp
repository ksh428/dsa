#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

// void initcode() {
// #ifndef ONLINE_JUDGE

// 	freopen("input.txt", "r", stdin);

// 	freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
// }

struct node{
      int max;
      int smax;
};

void buildtree(int a[],node tree[],int i,int s,int e){
      if(s==e){
            tree[i].max=a[s];
            tree[i].smax=INT_MIN;
            return;
      }
      int m=(e+s)/2;
      buildtree(a,tree,2*i,s,m);
      buildtree(a,tree,2*i+1,m+1,e);
      node left=tree[2*i];
      node right=tree[2*i+1];
      tree[i].max=max(left.max,right.max);
      tree[i].smax=min(max(left.smax,right.max),max(left.max,right.smax));
}
void updatetree(int a[],node tree[],int s,int e,int i,int idx,int val){
      if(s==e){
            a[idx]=val;
            tree[i].max=val;
            tree[i].smax=INT_MIN;
            return;
      }
      int m=(s+e)/2;
      if(idx>m){
            updatetree(a,tree,m+1,e,2*i+1,idx,val);
      }else{
            updatetree(a,tree,s,m,2*i,idx,val);
      }
      node left=tree[2*i];
      node right=tree[2*i+1];
      tree[i].max=max(left.max,right.max);
      tree[i].smax=min(max(left.smax,right.max),max(left.max,right.smax));
      return;
}
pair<int,int> query(node tree[],int s,int e,int i,int l,int r){
      if(l>e or r<s) return {INT_MIN,INT_MIN};
      if(s>=l and e<=r) return {tree[i].max,tree[i].smax};
      int m=(e+s)/2;
      auto la=query(tree,s,m,2*i,l,r);
      auto ra=query(tree,m+1,e,2*i+1,l,r);
      int amx=max(la.first,ra.first);
      int asmx=min(max(la.second,ra.first),max(la.first,ra.second));
      return {amx,asmx};
}

void solve() {
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      node tree[4*n];
      buildtree(a,tree,1,0,n-1);
      int q;
      cin>>q;
      while(q--){
            char c;
            int i,x;
            cin>>c>>i>>x;
            if(c=='U'){
                  i--;
                  updatetree(a,tree,0,n-1,1,i,x);
            }else{
                  i--;
                  x--;
                  auto it=query(tree,0,n-1,1,i,x);
                  cout<<it.first+it.second<<endl;
            }
      }
}


int32_t main() {
//	initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
