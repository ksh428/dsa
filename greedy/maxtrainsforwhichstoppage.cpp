#include <bits/stdc++.h>
using namespace std;


struct plat{
      int s,e,p;
};
bool comp(plat a,plat b){
      return a.e<b.e;
}

int maxStop(vector<plat>a)
{
      //just break platform wise
      int n=a.size();
      int ans=0;
      sort(a.begin(),a.end(),comp);
      // vector<int>vis(n,-1);
      map<int,pair<int,int>>m;
      for(int i=0;i<n;i++){
            if(m.find(a[i].p)==m.end()){
                  ans++;
                  m[a[i].p]={a[i].s,a[i].e};
            }else{
                  if(m[a[i].p].second<=a[i].s){
                        ans++;
                        m[a[i].p]={a[i].s,a[i].e};
                  }else continue;
            }
      }

      return ans;
}


int main()
{
      int n;
      cin>>n;
      vector<plat>a(n);
      for(int i=0;i<n;i++){
            cin>>a[i].s>>a[i].e>>a[i].p;
      }
      cout<<maxStop(a);

}
