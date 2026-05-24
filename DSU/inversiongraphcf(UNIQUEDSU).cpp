
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;



void solve() {
      int n;
      cin>>n;
      int p[n];
      map<int,int>m;
      for(int i=0;i<n;i++) cin>>p[i];
      set<int>st;

      st.insert(p[0]);
      for(int i=1;i<n;i++){
            int mx=0;
            auto it=st.lower_bound(p[i]);
            if(it==st.end()){
                  //new grp
                  st.insert(p[i]);
            }else{
                  vector<int>v;
                  for(auto j=it;j!=st.end();j++){
                        v.push_back(*j);
                        mx=max(mx,*j);
                  }
                  for(int x:v){
                        st.erase(x);
                  }
                  st.insert(mx);
            }
      }
      cout<<st.size()<<endl;




}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
