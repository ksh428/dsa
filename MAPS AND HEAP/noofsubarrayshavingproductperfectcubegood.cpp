//https://www.youtube.com/watch?v=TZhm7t5NTvY
//SIMILAR TO SUBARRAY WITH SUM 0
#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define endl "\n"
using namespace std;
void func(vector<ll>&v,ll n){//update the contributions of a[i]
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            v[i]++;
            v[i]%=3;
            n/=i;
        }
    }
    if(n!=1){
        v[n]++;
        v[n]%=3;

    }
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll>v(101,0);////initial config of prime factors
    int ans=0;
    map<vector<ll>,ll>m;
    m[v]++;
    for(ll i=0;i<n;i++){
        func(v,a[i]);
        ans+=m[v];
        m[v]++;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
}
//TC:O(N^3/2))
