class Solution
{
    public:
    #define pq pair<int,pair<int,int>>
    vector<int> mergeKArrays(vector<vector<int>> a, int k)
    {
        vector<int>ans;
        priority_queue<pq,vector<pq>,greater<pq>>q;
        for(int i=0;i<k;i++){
            q.push({a[i][0],{i,0}});
        }
        while(!q.empty()){
            pq curr=q.top();
            q.pop();
            ans.push_back(curr.first);
            int iele=curr.second.second;
            int iarr=curr.second.first;
            if(iele<k-1){
                q.push({a[iarr][iele+1],{iarr,iele+1}});
            }
        }
        return ans;

    }
};
