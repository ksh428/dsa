#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;
/*
p[j]-p[i-1]=s*j-s*(i-1)
p[j]-s*j=p[i-1]-s*(i-1)
q[j]=q[i-1]
*/
//
int solution(vector<int>&a,int s){
      int n=a.size();
      int ans=0;
      vector<ll>pref(n+1,0);
      vector<ll>q(n+1,0);
      for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+a[i-1];
            q[i]=pref[i]-s*i;
      }
      sort(q.begin()+1,q.end());
      map<ll,int>m;
      for(int i=0;i<=n;i++) m[q[i]]++;
      for(auto it:m){
            ans+=(it.second*(it.second-1)/2);
      }
      return (ans>1e9)?1e9:ans;
}
