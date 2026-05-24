
#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
int a[1000];
int dp[1000][1000];
ll sum(int s,int e){
    ll ans=0;
    for(int i=s;i<=e;i++) {
        ans+=a[i];
        ans%=100;
    }
    return ans;

}
ll func(int i,int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        ans=min(ans,func(i,k)+func(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j]=ans;

}

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<func(0,n-1)<<endl;
    return;
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
