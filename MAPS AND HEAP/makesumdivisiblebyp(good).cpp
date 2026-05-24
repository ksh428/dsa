class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int k=0;
        for(auto i : nums){
            k=(k+i)%p;
        }
        if(k==0) return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int other=0;
        int ans=n;
        for(int i=0;i<n;i++){
            other=(other+nums[i])%p;
            int tmp=(other-k);
            if(tmp<0)
                tmp+=p;
            if(mp.count(tmp)){
                ans=min(ans,i-mp[tmp]);
            }
            mp[other]=i;
        }
        return ans==n ? -1 : ans;
    }
};
//explanation in copy

