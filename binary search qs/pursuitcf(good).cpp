#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
bool ok(int a[],int b[],int m,int n){
      bool f=0;
       int tot=m+n;
       tot-=tot/4;
     if(tot>m){
           int mysc=m*100+a[tot-m-1];
           int lia;
           if(tot>=n) lia=b[n-1];
           else lia=b[tot-1];
           if(mysc>=lia){
                f=1;
           }
     }else{
           f=1;
     }
     return f;
}
void solve(){
     int n;
     cin>>n;
     int a[n];
     int b[n];
     for(int i=0;i<n;i++) cin>>a[i];
     for(int i=0;i<n;i++) cin>>b[i];
     sort(a,a+n,greater<int>());
     sort(b,b+n,greater<int>());
     for(int i=1;i<n;i++) a[i]+=a[i-1];
     for(int i=1;i<n;i++) b[i]+=b[i-1];
     int l=0,r=n;
     int ans=0;
     while(l<=r){
           int m=(l+r)/2;
           if(ok(a,b,m,n)){
                 ans=m;
                 r=m-1;
           }else l=m+1;
     }
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
