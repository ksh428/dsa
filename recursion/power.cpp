class Solution{
    public:
    #define ll long long
    //const int mod=1e9+7;

    long long power(int x,int n)
    {
        if(n==0) return 1;
        ll xp=power(x,n/2);
        ll xn=(xp%mod*xp%mod)%mod;
        if(n&1) xn=(xn%mod*x%mod)%mod;
        return xn%mod;
    }

};
