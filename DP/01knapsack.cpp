#include<bits/stdc++.h>
using namespace std;
struct knapsack{
 int wt;
 int val;
};
int findans(vector<knapsack>a,int n,int W)
{
    int dp[n+1][W+1];
    // base cases


}
int main()
{
    int n,W;
    cin>>n>>W;
    vector<knapsack>ar(n+1); // to store details
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i].wt>>ar[i].val;
    }
    findans(a,n,W);


}
