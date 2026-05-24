#include<bits/stdc++.h>
typedef long long ll;
#define mod 100000007
#define endl "\n"
using namespace std;

/*
dp(i,j): no of subsequences ending at i with gcd j
.gcd can take valuse from 1 to 100
 so for every j <i find the gcd of a[i] and g(1 to 100) and add it to the dp[i]
 at the end sum up dp[i][1]
*/
ll gcd(ll a,ll b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   vector<vector<ll>>dp(n,vector<ll>(101,0));
   dp[0][a[0]]=1;
   ll res=dp[0][1];
   for(int i=1;i<n;i++){
       for(int j=i-1;j>=0;j--){
           if(a[i]>a[j]){
               for(int g=1;g<=100;g++){
                   int newgcd=__gcd(g,a[i]);
                   dp[i][newgcd]=(dp[i][newgcd]+dp[j][g])%mod;
               }
           }
       }
       dp[i][a[i]]+=1;
       res=(res+dp[i][1])%mod;
   }
   cout<<res<<endl;

}
