
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int retclose(int a,int b,int c){
      if(abs(a-c)<abs(b-c)) return a;
      return b;
}
int dp[10001][10001];
int solve(int i,int sum,int a[]){//returns the sum closest to -sum from i..n
      if(i==n) return 0;
      if(dp[i][sum]!=INT_MAX) return dp[i][sum];
      int op1=solve(i+1,sum,a[i]);
      int op2=a[i]+solve(i+1,sum+a[i],a);
      return dp[i][sum]=retclose(op1,op2,sum);
}

int32_t main(){
      memset(dp,INT_MAX,sizeof(dp));
    int ans=solve(0,0,a);
  return 0;
}
