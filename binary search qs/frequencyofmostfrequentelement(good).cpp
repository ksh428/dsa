class Solution {
public:

    //binary search and sliding window
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];
        int maxi=1;
        for(int i=n-1;i>=1;i--){
            int l=0;
            int r=i;
            while(l<r){
                int m=(l+r)/2;
                //try to make the elements from m to i equal to nums[i]
                long long val=(nums[i]*1LL*(i-m))-(pref[i-1]-(m-1>=0?pref[m-1]:0));
                if(val<=k) r=m;
                else l=m+1;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};
