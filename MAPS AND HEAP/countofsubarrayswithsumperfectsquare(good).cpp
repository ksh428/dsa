#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;


void solve(){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int pref[n]={0};
      pref[0]=a[0];
      int premin=a[0];
      for(int i=1;i<n;i++) pref[i]=pref[i-1]+a[i],premin=min(premin,pref[i]);
      int ans=0;
      map<int,int>m;
      m[0]=1;
      for(int i=0;i<n;i++){
            for(int j=0;pref[i]-j*j>=premin;j++){
                  if(m.find(pref[i]-j*j)!=m.end()){
                        ans+=m[pref[i]-j*j];
                  }
            }
            m[pref[i]]++;
      }

      cout<<ans<<endl;
}


int main(){
    solve();
  return 0;
}
