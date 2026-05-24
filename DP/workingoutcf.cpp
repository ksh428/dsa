#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

ll maxcal(vector<vector<ll>>arr,int n,int m){
    int n=arr.size()-1;
    int m=arr[1].size()-1;
    vector<vector<ll>>dp1(n+1,vector<int>(m+1,0)); //top left to any cell right and down
    vector<vector<ll>>dp2(n+1,vector<int>(m+1,0));
    vector<vector<ll>>dp3(n+1,vector<int>(m+1,0));
    vector<vector<ll>>dp4(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j]=arr[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            dp2[i][j]=arr[i][j]+max(dp2[i+1][j],dp2[i][j+1]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            dp3[i][j]=arr[i][j]+max(dp3[i+1][j],dp3[i][j-1]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp4[i][j]=arr[i][j]+max(dp4[i-1][j],dp4[i][j+1]);
        }
    }
    //now conside all values of i,j as int point
    ll ans=0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            ll v1=dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1];
            ll v2=dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j];
            ans=max({ans,v1,v2});
        }
    }
    return ans;


}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<ll>>arr(n+1,vector<ll>(m+1,0));
   for(int i=1;<=n;i++){
       for(int j=1;j<=m;j++) cin>>arr[i][j];
   }
   cout<<maxcal(arr,n,m)<<endl;

}
