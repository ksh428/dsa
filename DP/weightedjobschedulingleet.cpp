//https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

class Solution {
public:
struct Job{
    int start,finish,profit;
};
static bool myfunction(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
int binarySearch(Job jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=e.size();
        Job arr[n];
        for(int i=0;i<n;i++){
            arr[i].start=s[i];
            arr[i].finish=e[i];
            arr[i].profit=p[i];
        }
        sort(arr, arr+n, myfunction);
        int dp[n];
        dp[0]=arr[0].profit;
        for (int i=1; i<n; i++)
        {
            int inclProf = arr[i].profit;
            int l = binarySearch(arr, i);
            if (l != -1)
                inclProf += dp[l];
            // Store maximum of including and excluding
            dp[i] = max(inclProf, dp[i-1]);
        }
        return dp[n-1];
    }
};
