
//DP: O(N^2)
#include <bits/stdc++.h>

using namespace std;
int k;

int dp[1001][1001];

int removals(int a[],int l,int r){
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    if((a[r]-a[l])<=k) return 0;
    return dp[l][r]= 1+min(removals(a,l+1,r),removals(a,l,r-1));

}

int main()
{
    memset(dp,-1,sizeof(dp));
   int a[] = {1, 5, 6, 2, 8};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a,a+n);
    k = 2;
    cout << removals(a, 0, n-1);
    return 0;
}

//binary search
int main()
{
  //  memset(dp,-1,sizeof(dp));
   int a[] = {1, 5, 6, 2, 8};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a,a+n);
    k = 2;
    int ans=n-1;
    for(int i=0;i<n;i++){
        int idx=upper_bound(a+i,a+n,a[i]+k)-a-1;
        ans=min(ans,n-(idx-i+1));
    }
    cout<<ans;

}
//nlogn
