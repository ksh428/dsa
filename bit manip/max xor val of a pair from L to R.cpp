#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
void solve(){
      int l,r;
      cin>>l>>r;
      int idx;
      for(int i=32;i>=0;i--){
            int v1=l&(1<<i);
            int v2=r&(1<<i);
            if(v1!=v2){
                  idx=i;
                  break;
            }
      }
      int ans=0;
      for(int i=0;i<=idx;i++){
            ans+=(1<<i);
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
