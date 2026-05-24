class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0;
        vector<int>v(3,0);
        int l=0,r=0;
        while(r<n){
            v[s[r]-'a']++;
            while(v[0] and v[1] and v[2]){
                ans+=n-r;
                v[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
