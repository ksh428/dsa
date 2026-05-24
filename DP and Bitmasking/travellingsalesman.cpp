

#include <bits/stdc++.h>

using namespace std;

int n=4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};


int finalval=(1<<n)-1; //1111

int dp[16][4];

int tsp(int mask,int pos){
    if(mask==finalval) return dist[pos][0];
    if(dp[mask][pos]!=-1) return dp[mask][pos];

    int ans=INT_MAX;

    for(int i=0;i<n;i++){//trverse all the cities
        if((mask&(1<<i))==0){//vity not visited
            int temp=dist[pos][i]+tsp(mask|(1<<i),i);
            ans=min(ans,temp);
        }
    }
    return dp[mask][pos]= ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<tsp(1,0);  //0001

}


