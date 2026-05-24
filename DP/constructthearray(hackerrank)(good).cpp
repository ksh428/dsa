long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long dp1[n],dp2[n];
    //dp1[i]: no of arrays with last char x
    //dp2[i]:no of arrays with last char not x
    dp1[0]=(x==1)?1:0;
    dp2[0]=(x==1)?0:1;
    for(int i=1;i<n;i++){
        dp1[i]=dp2[i-1];
        dp2[i]=((dp1[i-1]*(k-1))%mod+(dp2[i-1]*(k-2))%mod)%mod;
    }
    return dp1[n-1];

}
