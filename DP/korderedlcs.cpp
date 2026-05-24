#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
int n,m,k;
int a[2005],b[2005];

ll dp[2005][2005][8];

ll solve(int n,int m,int k){
    if(k<0) return -1e7;
    if(n==0 || m==0) return 0;
    if(dp[n][m][k]!=-1) return dp[n][m][k];
    if(a[n]==b[m]) return dp[n][m][k]=1+solve(n-1,m-1,k);
    else {
        if(k>0){
            return dp[n][m][k] = 1+solve(n-1,m-1,k-1);
        }else return dp[n][m][k] =max(solve(n-1,m,k),solve(n,m-1,k));
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=m;j++) cin>>b[j];
    cout<<solve(n,m,k);


}
