#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;
bool canpal(string s){
      int n=s.size();
      unordered_map<char,int>m;
      for(char c:s){
            m[c]++;
      }
      int c=0;
      for(auto it:m){
            if(it.second&1) c++;
      }
      return c<=1;
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(canpal(s)){
          int l=0,r=n-1;
          int ans=0;
          while(l<r){
                if(s[l]==s[r]){
                      l++;
                      r--;
                }else{
                      int k=r;
                      while(k>l and s[k]!=s[l]) k--;
                      if(k==l) {
                            swap(s[l],s[l+1]);
                            ans++;
                      }else{
                            while(k<r){
                                  swap(s[k],s[k+1]);
                                  ans++;
                                  k++;
                            }
                            l++;
                            r--;
                      }
                }
          }
          cout<<ans;
    }else cout<<"-1";

}
