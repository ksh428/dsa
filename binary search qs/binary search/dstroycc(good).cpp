#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool possible(ll m,ll g[],ll n,ll k){
    ll s=0;
    for(ll i=0;i<n;i++){
        if(g[i]<m) s+=g[i];
        else s+=m;
    }
    return s/m>=k;

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll g[n];
	ll sum=0;
	for(ll i=0;i<n;i++){
	    cin>>g[i];
	    sum+=g[i];
	}
	ll l=0;//min minutes
	ll r=sum;//max minutes (if k=1)
	ll ans=0;
	while(l<=r){
	    ll m=l+(r-l)/2;
	    if(possible(m,g,n,k)){ //check whether if the operation is possible for m minutes
	        l=m+1;
	        ans=m;
	    }else r=m-1;
	}

	cout<<ans<<endl;

}
