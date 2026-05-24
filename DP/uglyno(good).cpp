
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0) return 0;
        int dp[n];
        //dp(i):ith ugly no.
        //se notes
        dp[0]=1;
        int p2,p3,p5;
        p2=p3=p5=0;
        for(int i=1;i<n;i++){
            dp[i]=min(2*dp[p2],min(3*dp[p3],5*dp[p5]));
            if(dp[i]==2*dp[p2]) p2++;
            if(dp[i]==3*dp[p3]) p3++;
            if(dp[i]==5*dp[p5]) p5++;
        }
        return dp[n-1];

    }
};
//better and intuitive soln
class Solution {
public:
    #define ll long long
    int nthUglyNumber(int n) {
       set<ll>ans;
        set<ll>st;
        st.insert(1);
        //TC: nlogn (as every element has 3 options)
        while(ans.size()<n){
            ll curr=*st.begin();
            ans.insert(curr);
            st.erase(curr);
            st.insert((ll)2*curr);
            st.insert((ll)3*curr);
            st.insert((ll)5*curr);
        }
        return *ans.rbegin();
    }
};
