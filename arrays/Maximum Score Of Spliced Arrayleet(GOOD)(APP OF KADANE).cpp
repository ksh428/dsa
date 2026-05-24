
class Solution {
public:
    int solve(vector<int>n1,vector<int>n2){//sum(n1)+max(diff)(s2-s1)
        int s=0;
        for(auto it:n1) s+=it;
        int diff=0;
        int mx=0;
        for(int i=0;i<n1.size();i++){//similar to kadane
            diff+=n2[i]-n1[i];
            if(diff<0) diff=0;
            mx=max(mx,diff);
        }
        return s+mx;

    }
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        //the ans will be either sum(n1)+best_subarray_diff(n2-n1) or sum(n2)+best_subarray_diff(n1-n2);
        return max(solve(n1,n2),solve(n2,n1));
    }
};
