
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	    int n,q;
	    cin>>n>>q;
	    vector<ll>a(n);
	    vector<ll>k(q);
	    for(ll i=0;i<n;i++) cin>>a[i];
	    for(ll i=0;i<q;i++) cin>>k[i];
	    vector<ll>pref(n);
	    pref[0]=a[0];
	    for(int i=1;i<n;i++) pref[i]=pref[i-1]+a[i];
	    //partial_sum(a.begin(),a.end(),pref.begin());
	    ll asf=0;//arrow so far
	    for(auto arrow:k){
	        asf+=arrow;
	        if(asf>=pref.back()) asf=0;//thor
	        auto it=lower_bound(pref.begin(),pref.end(),asf);
	        cout<<distance(it,pref.end())-(*it==asf)<<endl;
	    }
}
