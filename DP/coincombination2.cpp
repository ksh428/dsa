e
//CSES..
#include <bits/stdc++.h>
#define m 10000007
using namespace std;

int main()
{
   int n,x;
   cin>>n>>x;
   int c[n+1];   //nof of ele,sum
   for(int i=1;i<=n;i++) cin>>c[i];
   int dp[x+1];
   memset(dp,0,sizeof(dp));
   dp[0]=1;
   for(int i=1;i<=n;i++){//coins
       for(int j=0;j<=x;j++){//value
           if(j-c[i-1]>=0){
               dp[j]+=dp[j-c[i-1]];
               dp[j]%=m;
           }

       }
   }
   cout<<dp[x];
}

