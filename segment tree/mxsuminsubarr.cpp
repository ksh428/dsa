#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct node{
      int sum;
      int mxsum;
      int bestpref;
      int bestsuff;
};
void buildtree(int a[],node tree[],int s,int e,int i){
      if(s==e){
            tree[i].sum=a[s];
            tree[i].mxsum=a[s];
            tree[i].bestsuff=a[s];
            tree[i].bestpref=a[s];
            return;
      }
      int m=(s+e)/2;
      buildtree(a,tree,s,m,2*i);
      buildtree(a,tree,m+1,e,2*i+1);
      tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
      tree[i].bestpref=max(tree[2*i].bestpref,tree[2*i].sum+tree[2*i+1].bestpref);
      tree[i].bestsuff=max(tree[2*i+1].bestsuff,tree[2*i+1].sum+tree[2*i].bestsuff);
      tree[i].mxsum=max({tree[2*i].bestsuff+tree[2*i+1].bestpref,tree[2*i].mxsum,tree[2*i+1].mxsum});
}
node query(node tree[],int s,int e,int i,int l,int r){
      if (l > e or r < s) {
            node ans;
            ans.sum=INT_MIN;
            ans.mxsum=INT_MIN;
            ans.bestpref=INT_MIN;
            ans.bestsuff=INT_MIN;
            return ans;
      }
      if(s>=l and e<=r) return tree[i];
      node ans;
      int m=(s+e)/2;
      node la=query(tree,s,m,2*i,l,r);
      node ra=query(tree,m+1,e,2*i+1,l,r);
     // int ans=max({la.bestsuff+ra.bestpref,la.sum,ra.sum});
      ans.sum=la.sum+ra.sum;
      ans.bestpref=max(la.bestpref,la.sum+ra.bestpref);
      ans.bestsuff=max(ra.bestsuff,ra.sum+la.bestsuff);
      ans.mxsum=max({la.mxsum,ra.mxsum,la.bestsuff+ra.bestpref});
      return ans;
}

void solve() {
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      node tree[4*n];
      buildtree(a,tree,0,n-1,1);
      int m;
      cin>>m;
      while(m--){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            node ans=query(tree,0,n-1,1,x,y);
            cout<<ans.mxsum<<endl;
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
