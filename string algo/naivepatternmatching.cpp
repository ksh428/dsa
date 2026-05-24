#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool ok(string s,string p){
      int n=s.size();
      int m=p.size();
      for(int i=0;i<=n-m;i++){
            int f=0;
            for(int j=0;j<m;j++){
                  if(s[i+j]!=p[j]){
                        f=1;
                        break;
                  }
            }
            if(f==0) return 1;
      }
      return 0;
}

void solve() {
      string s,p;
      cin>>s>>p;
      cout<<ok(s,p);


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      solve();
	return 0;
}
