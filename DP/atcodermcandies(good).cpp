

#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define endl "\n"
using namespace std;
ll dp[105][100005];


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
     //dp[i][j]:no of ways to distribute j candles among i childs
    for(int i=0;i<=a[0];i++) dp[0][i]=1;//base case
    for(int i=1;i<n;i++){
          vector<int>pref(k+1);
          pref[0]=dp[i-1][0];
          for(int j=1;j<=k;j++){
                pref[j]=(pref[j-1]+dp[i-1][j])%mod;
          }
          for(int j=0;j<=k;j++){
                if(j-a[i]-1>=0)
                dp[i][j]=(pref[j]-pref[j-a[i]-1]+mod)%mod;/// dp[j]+dp[j-1]+dp[j-2]+...dp[j-a[i]-1]
                else dp[i][j]=pref[j];
          }
    }
   cout<<dp[n-1][k];
}
