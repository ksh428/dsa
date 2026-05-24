//bottom up tbd
//take copy and revise

#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int dp[1001][1001][2];
int n,k;



//0 forward
ll solve(int index,int rem,int side){
    if (dp[index][rem][side] != -1)
		return dp[index][rem][side];
	if (rem == 1)
		return 0;
	ll ans1 = 0, ans2 = 0;
	if (side == 0) {
		ans1 = 1 + (index - 1 >= 1 ? solve(index - 1, rem - 1, 1) : 0);
		ans2 = (index + 1 <= n ? solve(index + 1, rem, 0) : 0);
	} else {
		ans1 = (index - 1 >= 1 ? solve(index - 1, rem, 1) : 0LL);
		ans2 = 1 + (index + 1 <= n ? solve(index + 1, rem - 1, 0) : 0);
	}
	dp[index][rem][side] = (ans1 + ans2) % mod;
	return dp[index][rem][side];
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){

	   cin>>n>>k;
	   for(int i=0;i<=n;i++){
	       for(int j=0;j<=k;j++){
	           dp[i][j][0]=-1;
	           dp[i][j][1]=-1;
	       }
	   }
	   ll ans=1+solve(1,k,0);
	   cout<<ans<<endl;

	}
}

//BETTER APPROACH

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int long long
const ll mod = 1e9 + 7;

int dp[1005][1005];
int func(int forward, int backward, int decay){

     if(decay==1 || forward ==0){
         return dp[forward][decay] =1;
     }

     if(dp[forward][decay]!=-1){

         return dp[forward][decay];
     }

     return dp[forward][decay] = (func(backward,forward,decay-1) + func(forward-1,backward+1,decay))%mod;

}
//f(f,b): no of particles produced when there are f fwd planes and b backwd planes // draw and understand recurence

void solve()
{

   int n;
   cin>>n;

   int k;
   cin>>k;

   memset(dp,-1,sizeof(dp));
   cout<< func(n,0,k)<<endl;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
