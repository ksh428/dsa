
class Solution {
public:

   vector<int> dp;
    int sub(vector<int> &day, vector<int> &cost, int si)    // subproblem
    {
        int n = day.size();
        if(si>=n)   return 0;

        if(dp[si])  return dp[si];      // ie we aready knows the answer so no need to re calculate , return answer.

        int cost_day = cost[0] + sub(day , cost , si+1);

        int i;
        for(i = si ; i<n and day[i]<day[si]+7 ; i++);
        int cost_week = cost[1] + sub(day, cost, i);

        for(i = si ; i<n and day[i]<day[si]+30 ; i++);
        int cost_month = cost[2] + sub(day, cost, i);

        dp[si] = min({cost_day, cost_week , cost_month  });   // we store answer for future references

        return dp[si];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(367);
        return sub(days,costs,0);
    }
};
//BOTTOM UP
/*
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(366);
        //dp(i) cost to travel for i days
        set<int>s;
        for(int x:days) s.insert(x);
        //dp[0]=0;
        for(int i=1;i<366;i++){

            if(s.find(i)!=s.end()){
                int op1,op2,op3;
                op1=costs[0]+dp[i-1];
                op2=costs[1]+dp[max(i-7,0)];
                op3=costs[2]+dp[max(i-30,0)];
                dp[i]=min(op1,min(op2,op3));
            }else  dp[i]=dp[i-1];//non travel day
        }
        return dp[365];

    }
};
*/
