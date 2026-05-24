#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    int forward[n+10],backward[n+10];
	    forward[0]=backward[n+1]=0;
	    //f(i) gcd of nos from 0 to i
	    //b(i) gcd of nos from i to n

	    vector<int>a(n+1);
	    for(int i=1;i<=n;i++) cin>>a[i];
	    for(int i=1;i<=n;i++) forward[i]=__gcd(forward[i-1],a[i]);
	    for(int i=n;i>=1;i--) backward[i]=__gcd(backward[i+1],a[i]);


	    while(q--){
	        int l,r;
	        cin>>l>>r;
	        int gc=0;
	       // for(int i=1;i<=l-1;i++) gc=__gcd(gc,a[i]);
	       // for(int i=r+1;i<=n;i++) gc=__gcd(gc,a[i]);


	        cout<<__gcd(forward[l-1],backward[r+1])<<endl;
	    }

	}
}
