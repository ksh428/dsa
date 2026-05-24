

// https://cses.fi/problemset/task/2181


#include <bits/stdc++.h>

using namespace std;
int m;
int n;

void generatemasks(int mask,vector<int>&masks,int i,int nextmask)
{
    if(i==n)
    {
        masks.push_back(nextmask);
        return;
    }
    if(mask&(1<<i))
    {
        generatemasks(mask,masks,i+1,nextmask);
    }
    if(!mask&(1<<i) and !mask&(1<<(i+1)))
    {
        // place vertical
        generatemasks(mask,masks,i+2,nextmask);
    }
    if(!mask&(1<<i))
    {
        //place horizaontal
        generatemasks(mask,masks,i+1,nextmask|(1<<i));
    }
}

int solve(int i,int mask)
{
    if(i==m+1)
    {
        if(mask==0) return 1;
        else return 0;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=0;
    vector<int>masks;
    generatemasks(mask,masks,0,0);
    for(auto it:masks)
    {
        ans+=solve(i+1,it);
    }
    return dp[i][mask]=ans;
}

int main()
{
  

}


