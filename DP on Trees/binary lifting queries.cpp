#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int depth[200001];
int dp[20001][21]; // ith ancestor of the node

void binarylifting(int i, int par)
{
    dp[i][0]=par;
    for(int k=1;k<21;k++)
    {
        if(dp[i][k-1]==-1)
        {
            dp[i][k]=-1;
        }else{
            int intm=dp[i][k-1];
            dp[i][k]=dp[intm][k-1];
        }
    }
    for(int j:adj[i])
    {
        if(j==par) continue;
        binarylifting(j,i);
    }
}

int query(int i, int k)
{
    if(i==-1) return -1;
    if(k==0) return i;

    for(int j=20;j>=0;j--)
    {
        if(k&(1<<j))
        {
            return query(dp[i][j], k-(1<<j));
        }
    }

    return i;
}
int main() {
    int n;
	cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp,)
}
