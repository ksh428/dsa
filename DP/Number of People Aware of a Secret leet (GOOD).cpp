
class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int peopleAwareOfSecret(int n, int d, int f) {
        ll dp[n+1];//dp(i): no of people getting to know the secret in ith day
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        ll noofpeoplesharingsecret=0;
        for(int i=2;i<=n;i++){
            ll noofnewpeoplesharingsecret=(i-d>=0)?dp[i-d]:0;
            ll noofpeopleforgettingsecret=(i-f>=0)?dp[i-f]:0;
            noofpeoplesharingsecret+=(noofnewpeoplesharingsecret-noofpeopleforgettingsecret+mod)%mod;
            dp[i]=noofpeoplesharingsecret;
        }
        ll ans=0;
        for(int i=n-f+1;i<=n;i++){//all people who came to knw the secret before f days will forget it by nth day so for them no contribution
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};
