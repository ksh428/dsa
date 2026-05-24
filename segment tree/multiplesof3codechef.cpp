#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct node{
      int a[3];
};
node tree[400004];
int lazy[400004];


void build(int s,int e,int i){
      if(s==e){
            tree[i].a[0]=1;
            tree[i].a[1]=0;
            tree[i].a[2]=0;
            return;
      }
      int m=(e+s)/2;
      build(s,m,2*i);
      build(m+1,e,2*i+1);
      tree[i].a[0]=tree[2*i].a[0]+tree[2*i+1].a[0];
      tree[i].a[1]=tree[2*i].a[1]+tree[2*i+1].a[1];
      tree[i].a[2]=tree[2*i].a[2]+tree[2*i+1].a[2];
}

void shift(int i){
      int v=tree[i].a[2];
      tree[i].a[2]=tree[i].a[1];
      tree[i].a[1]=tree[i].a[0];
      tree[i].a[0]=v;
}

void update(int s,int e,int i,int a,int b){
      if(lazy[i]!=0){
            int d=lazy[i];
            lazy[i]=0;
            if(s!=e){
               lazy[2*i]+=d;
               lazy[2*i+1]+=d;
            }
            d%=3;
            for(int j=0;j<d;j++){//adding by j is equivalent to right shfting by j//see copy
                  shift(i);
            }
      }
      if(a>e or b<s) return;
      if(s>=a and e<=b){
            shift(i);
            if(s!=e){
                  lazy[2*i]+=1;
                  lazy[2*i+1]+=1;
            }
            return;
      }
      int m=(e+s)/2;
      update(s,m,2*i,a,b);
      update(m+1,e,2*i+1,a,b);
       tree[i].a[0]=tree[2*i].a[0]+tree[2*i+1].a[0];
      tree[i].a[1]=tree[2*i].a[1]+tree[2*i+1].a[1];
      tree[i].a[2]=tree[2*i].a[2]+tree[2*i+1].a[2];
}
int query(int i,int s,int e,int a,int b){
      if(lazy[i]!=0){
            int d=lazy[i];
            lazy[i]=0;
            if(s!=e){
                  lazy[2*i]+=d;
                  lazy[2*i+1]+=d;
            }
            d%=3;
            for(int j=0;j<d;j++){
                  shift(i);
            }
      }
      if(s>b or e<a) return 0;
      if(s>=a and e<=b){
            return tree[i].a[0];
      }
      int m=(s+e)/2;
      int l=query(2*i,s,m,a,b);
      int r=query(2*i+1,m+1,e,a,b);
      return l+r;
}

void solve() {
      int n,q;
      cin>>n>>q;
      build(0,n-1,1);
      while(q--){
            int c,a,b;
            cin>>c>>a>>b;
            if(c==1){
                  cout<<query(1,0,n-1,a,b)<<endl;
            }else{
                  update(0,n-1,1,a,b);
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
