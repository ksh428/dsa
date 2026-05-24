#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
/*

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll ts;
	    cin>>ts;
	    if(ts&1 && ts!=1){
	        //odd
	        //js needs to be even in the range 1 to ts-1
	       ll c=(ts-1)/2; //no of odds
	        cout<<c<<endl;

	    }else if(ts==1)
	    cout<<"0"<<endl;
	    else{
	        //ts is even
	        //js needs to be even from 2 to ts

	        int c=0;
	        int storets=ts;
	        while(ts%2==0){
	            ts/=2;
	            c++;
	        }
	        ll ans=0;

	        ll expr=pow(2,c+1);
	        //cout<<expr;
	        ll i=1;
	        ll temp=expr*i;
	        //cout<<temp;
	        //cout<<storets;
	        while(expr<storets){
	            ans++;
	            i++;
	            expr=temp*i;

	        }
	        cout<<ans<<endl;

	        //the above process is correct but gives TLE
	        //in the new process convert ts into the odd no. and find the number of even nos less than it;


	    }

	}
}
*/
int main(){
    //if ts is odd then we can directly print the no. of evens leaas than that
    //if even then do as above
    int t;
    cin>>t;
    while(t--){
        ll ts;
        cin>>ts;
        while(ts%2!=1){
            //even
            ts/=2;
        }
        cout<<(ts-1)/2<<endl;
    }
}
