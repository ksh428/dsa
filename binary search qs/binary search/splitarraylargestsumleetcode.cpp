class Solution {
public:
    bool valid(int x,vector<int>nums,int m){//return true if m or less subarras can be formed with largest sum <=x
        int sc=1;
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>x) return false;
            if(s+nums[i]<=x){
                s+=nums[i];
            }else{
                sc++;
                s=nums[i];
            }
        }
        return sc<=m;

    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int l=0;
        int r=1e9+1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(valid(mid,nums,m)){
                r=mid;
            }else l=mid+1;
        }
        return l;
    }
};
