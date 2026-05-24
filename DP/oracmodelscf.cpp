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
	    int n;
	    cin>>n;
	    int a[n+1];
	    a[0]=0;
	    for(int i=1;i<=n;i++) cin>>a[i];
	    //adjacent indices shud be div and elemnet shud be incr
	    //normal lis wil be on^2
	    vector<int>dp(n+1,1);
	    dp[0]=0;
	    for(int i=2;i<=n;i++){
	        int mx=0;
	        for(int j=1;j*j<=i;j++){//find divisors of i
	            if(i%j==0){
	                int d1,d2;
	                d1=j;
	                d2=i/j;
	               // if(a[d1]<a[i]){
	               //     mx=max(mx,dp[d1]);
	               // }
	               // if(a[d2]<a[i]) mx=max(mx,dp[d2]);
	               if(a[d1]<a[i]) dp[i]=max(dp[i],dp[d1]+1);
	               if(a[d2]<a[i]) dp[i]=max(dp[i],dp[d2]+1);
	            }
	        }
	        //dp[i]=1+mx;
	    }
	    int ans=1;
	    //for(int x:dp) cout<<x<<" ";
	    for(int x:dp){
	        if(x>ans) ans=x;
	    }
	    cout<<ans<<endl;

	}
}
