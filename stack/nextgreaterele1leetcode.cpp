
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++) mp[nums2[i]]=i;
        stack<int>st;
        vector<int>res(nums2.size(),-1);
        for(int i=0;i<nums2.size();i++){
            if(st.empty()) st.push(i);
            else if(nums2[i]<=nums2[st.top()]) st.push(i);
            else{
                while(!st.empty() and nums2[st.top()]<nums2[i]){
                    res[st.top()]=nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int i:nums1){
            ans.push_back(res[mp[i]]);
        }
        return ans;

    }
};
