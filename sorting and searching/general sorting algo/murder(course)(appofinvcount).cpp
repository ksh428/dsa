#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
int merge(int a[],int l,int m,int r){
      int i=l,j=m,k=0;
      int temp[r-l+1];
      int c=0;
      while(i<m and j<=r){
            if(a[i]<a[j]){
                  c+=(a[i]*(r-j+1));
                  temp[k++]=a[i++];
            }else temp[k++]=a[j++];
      }
      while(i<m) temp[k++]=a[i++];
      while(j<=r) temp[k++]=a[j++];
      for(int i=l,k=0;i<=r;k++,i++) a[i]=temp[k];
      return c;
}
int mergesort(int a[],int l,int r){
      int c=0;
      if(l<r){
            int m=(l+r)/2;
            c+=mergesort(a,l,m);
            c+=mergesort(a,m+1,r);
            c+=merge(a,l,m+1,r);
      }
      return c;
}
void solve(){
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++) cin>>a[i];
     int ans=mergesort(a,0,n-1);
     cout<<ans<<endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
