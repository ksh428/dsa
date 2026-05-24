#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
void solve(){

}
int main(){
      int a[] = {10, 12, 11};
      int n = sizeof(a) / sizeof(a[0]);
      int ans=0;
      for(int i=0;i<n-1;i++){
            int mn=a[i],mx=a[i];
            unordered_set<int>s;
            s.insert(a[i]);
            for(int j=i+1;j<n;j++){
                  if(s.find(a[j])!=s.end()) break;
                  else s.insert(a[j]);
                  mn=min(mn,a[j]);
                  mx=max(mx,a[j]);
                  if(mx-mn==j-i){
                        int l=j-i+1;
                        if(l>ans){
                              ans=l;
                        }
                  }
            }
      }
      cout<<ans;
}

//o(n^2)
