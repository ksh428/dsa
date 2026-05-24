#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool ok(int m,vector<pair<int,int>>vp){//return 1 if ans is possible with m power
      for(auto it:vp){
            if(it.first>=m) return 0;
            else{
                  m+=it.second;
            }
      }
      return 1;

}
void solve(){
     int n;
     cin>>n;
     vector<pair<int,int>>vp;
     vector<vector<int>>v(n,vector<int>());
     for(int i=0;i<n;i++){
           int k;
           cin>>k;
           int req=0;
           for(int j=0;j<k;j++){
                 int x;
                 cin>>x;
                 req=max(req,x+1-j);
                 v[i].push_back(x);
           }
           vp.push_back({req,k});
     }
     sort(vp.begin(),vp.end());
     int l=1,r=1e9+7;
     int ans;
     while(l<=r){
           int m=l+(r-l)/2;
           if(ok(m,vp)){
                 ans=m;
                 r=m-1;
           }else l=m+1;
     }
     cout<<ans-1<<endl;

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
