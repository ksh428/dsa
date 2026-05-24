class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& a, int k) {
        int n=a.size();
        //max(yi+yj+|xi-xj|)=max(yi+yj+xj-xi)//since x cor is sorted
        //=max(xj+yj+(yi-xi))
        //(xj+yj+max(yi-xi))  where i<j and xj-xi<=k

        priority_queue<pair<int,int>>pq;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(!pq.empty() and (a[i][0]-pq.top().second)>k) pq.pop();//understand this why it works
            if(!pq.empty()){
                ans=max(ans,a[i][0]+a[i][1]+pq.top().first);
            }
            pq.push({a[i][1]-a[i][0],a[i][0]});

        }
        return ans;
    }
};
