#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

ll dp[401][401];
ll sum[405][405];//prefix sum can also be used

ll func(vector<int>a,int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll mincost=INT_MAX;
    for(int k=i;k<j;k++){
        mincost=min(mincost,func(a,i,k)+func(a,k+1,j)+sum[i][j]);
    }
    return dp[i][j]=mincost;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        sum[i][j]=a[j]+((i==j)?0:sum[i][j-1]);
	    }
	}
	cout<<func(a,1,n);


}

//BOTTOM UP

#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

ll dp[401][401];
ll sum[401][401];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dp[i][i]=0;

    }
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        sum[i][j]=a[j]+((i==j)?0:sum[i][j-1]);
	    }
	}

    for(int w=2;w<=n;w++){
        for(int l=1;l+w<=n+1;l++){
           int r=l+w-1;
           dp[l][r]=INT_MAX;
           for(int k=l;k<r;k++){
               dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[l][r]);
           }
           //dp[l][r]=minv;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<sum[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[1][n];
}
