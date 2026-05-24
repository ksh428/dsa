//https://www.spoj.com/problems/GNYR09F/


#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp[101][101][2];

int func(int n,int k,int last){  //dp(n,k,f) no of strings of length n with adjbc k  with nth(last) char f
    if(n==0) return 0;

    if(n==1){
        if(k==0) return 1;
        else return 0;
    }
    if(dp[n][k][last]!=-1) return dp[n][k][last];
    int ans=-1;
    if(f==1){
        ans=func(n-1,k,0)+func(n-1,k-1,1);
    }else ans=func(n-1,k,0)+func(n-1,k,1);
    return dp[n][k][last]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int num,n,k;
	    cin>>num>>n>>k;
	    memset(dp,-1,sizeof(dp));
	    int ans=func(n,k,0)+func(n,k,1);
	    cout<<num<<" "<<ans<<endl;
	}
}
