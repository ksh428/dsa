


#include <bits/stdc++.h>
#define mod 100000

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int>v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   vector<vector<int>>dp(m+1,vector<int>(n,0));
   for(int i=0;i<n;i++){
       if(i==0){//base case
           //first element
           if(a[i]!=0) dp[a[i]][i]=1;
           else{
               for(int i=1;i<=m;i++){
                   dp[j][i]=1;
               }
           }
       }
       if(a[i]!=0){
           dp[a[i]][i]=dp[a[i]-1][i-1]+dp[a[i]][i-1]+(a[i]+1<=m)?dp[a[i]+1][i-1]%mod:0;
       }else{
           for(int j=1;j<=m;j++){
               dp[j][i]=dp[j][i-1];
               dp[j][i]=dp[j][i]%mod+dp[j-1][i-1]%mod;
               if(j<m) dp[j][i]=dp[j][i]%mod+dp[j+1][i-1]%mod;
               dp[j][i]%=mod;

           }

       }
   }
   if(a[n-1]!=0) cout<<dp[a[n-1]][n-1]%mod;
   else {
       int s=0;
       for(int i=1;i<=m;i++){
           s=s%mod+dp[j][n-1]%mod;
       }
       cout<<s;
   }
}
