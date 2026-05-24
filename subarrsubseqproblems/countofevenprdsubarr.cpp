#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define endl "\n"
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
int main() {
    FIO;
    test
    {
      ll n; cin>>n;
      vector<ll>a(n);
      for(auto &it:a) cin>>it;
      ll ans=(n*(n+1))/2;//total no of subarr of arr of size n is
      ll ans1=0;
      ll ok=0;
      for(ll i=0;i<n;i++){
          if(a[i]%2==0){
              ok=0;
          }
          else{
              ok++;
              ans1+=ok;
          }
      }
      cout<<ans-ans1<<endl;
    }
	return 0;
}

//DP SOLN MYSELF

#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
        ll a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        ll dp[n][2];//dp(i,0):no of subarr ending at i having even prd
		//bc
		if(a[0]&1){
			dp[0][1]=1;
			dp[0][0]=0;
		}else dp[0][1]=0,dp[0][0]=1;
		for(int i=1;i<n;i++){
			if(a[i]%2==0){
				dp[i][0]=dp[i-1][0]+1+dp[i-1][1];
				dp[i][1]=0;
			}else{
				dp[i][0]=dp[i-1][0];
				dp[i][1]=1+dp[i-1][1];
			}

		}
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=dp[i][0];
		}
		cout<<ans<<endl;

	}
}
