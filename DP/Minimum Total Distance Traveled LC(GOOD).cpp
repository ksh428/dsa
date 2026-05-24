
class Solution {
public:
#define ll long long
vector<int>robots,fact;
ll dp[101][10001];
    ll solve(int i,int j){//return min dist travelled when we are at ith robot and jth fact in sorted arrays
        if(i>=robots.size()){
            return 0;
        }
        if(j>=fact.size()){
            return 1e13;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        ll op1=solve(i+1,j+1)+abs(robots[i]-fact[j]);//make pair of ith robot with jth fact
        ll op2=solve(i,j+1);//dont make pair
        return dp[i][j]=min(op1,op2);
    }
    long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& b) {
        robots=a;
        memset(dp,-1,sizeof(dp));
        for(auto &it:b){
            while(it[1]>0){
                fact.push_back(it[0]);
                it[1]--;
            }
        }
        sort(robots.begin(),robots.end());
        sort(fact.begin(),fact.end());
        return solve(0,0);
    }
};
