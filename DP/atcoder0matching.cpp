//dp with bitmasking

#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;

ll dp[22][(1<<22)];

ll match(vector<vector<int>>compat,int i,int mask,int n){   //f(i,mask):no of ways to make pairs from i+1 th men to remaining set of women represented as mask(since its boolean)
    //bc
    if(i==n+1){
        //all men finished
        //then if mask is 0 1 valid ans got
        if(mask==0) return 1;
        else return 0;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];
    ll ans=0;
    for(int w=0;w<n;w++){
        //check whether ith w is available
        bool available=((1<<w)&mask==0)?0:1;
        if(available and compat[i][w+1]==1){
            ans+=match(compat,i+1,mask^(1<<w),n);
        }
    }
    return dp[i][mask]=ans;

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<vector<int>>compat(n+1,vector<int>(n+1));
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        cin>>compat[i][j];
	    }
	}
	cout<<match(compat,1,(1<<n)-1,n);

}
