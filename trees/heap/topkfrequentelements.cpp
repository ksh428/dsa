class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--){
            int x=pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;

    }
};
