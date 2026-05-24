#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll ts;
	    cin>>ts;
	    if(ts&1 && ts!=1){
	        //odd
	        //js needs to be even in the range 1 to ts-1
	        ll c=0;
	        for(ll i=2;i<ts;i+=2)
	        c++;
	        cout<<c<<endl;

	    }else if(ts==1)
	    cout<<"0"<<endl;
	    else{
	        //ts is even
	        //js needs to be even from 2 to ts
	        int c=0;
	        while(ts%2==0){
	            ts/=2;
	            c++;
	        }
	        ll ans=0;

	        ll expr=pow(2,c+1);
	        cout<<expr;
	        ll i=1;
	        ll t=expr*i;
	        while(expr<=ts){
	            ans++;
	            i++;
	            expr=t*i;

	        }
	        cout<<ans<<endl;

	    }

	}
}
