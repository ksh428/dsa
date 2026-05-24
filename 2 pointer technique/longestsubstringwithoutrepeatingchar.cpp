class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       //unordered_map<char,int>m;//char,pos
        vector<int>m(256,-1);
        int l=0,r=0;
        int n=s.size();
        int ans=0;
        while(r<n){
            if(m[s[r]]!=0){
                l=max(m[s[r]]+1,l);
            }
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;

        }
        return ans;
    }
};

//TC: O(N)  SC:O(N)
