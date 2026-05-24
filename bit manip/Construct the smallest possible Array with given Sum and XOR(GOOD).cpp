
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

//see main copy for exp

void solve() {
      int s,x;
      cin>>s>>x;
      if(x>s or (x%2 != (s%2))){
            cout<<"NOt posible";
            return ;
      }
      if(s==x){
            cout<<1<<endl;
            cout<<s<<endl;
            return;
      }
      int xreq=(s-x)/2;
      if((x&xreq)!=1){
            cout<<2<<endl;
            cout<<xreq<<" "<<a+xreq;
            return;
      }
      cout<<3<<endl;
      cout<<(s-x)/2<<" "<<(s-x)/2<<" "<<x<<" ";

}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
