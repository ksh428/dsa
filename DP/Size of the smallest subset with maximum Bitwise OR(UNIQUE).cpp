
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int minSubset(int a[],int n,int x){
     vector<vector<int>>dp(n+1,vector<int>(dp,1e9));
     dp[0][0]=0;
     for(int i=0;i<n;i++){
           for(int j=0;j<=x;j++){
                 dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                 dp[i+1][j|a[i]]=min(dp[i+1][j|a[i]],1+dp[i][j]);
           }
     }
     return dp[n][x];
}

void solve(){
    int a[] = { 5, 1, 3, 4, 2 };
    int n = sizeof(a) / sizeof(0);
    int x=0;
    for(int i=0;i<n;i++) x|=a[i];

    // Function Call
    cout << minSubset(a, n, x) << '\n';


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
  return 0;
}
