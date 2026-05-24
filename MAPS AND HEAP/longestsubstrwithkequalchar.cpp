
class Solution{
    public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n=s.size();
        int i=0,j=0;
        int ans=-1;
        unordered_map<char,int>m;
        while(j<=n){
            if(m.size()<k){
                m[s[j]]++;
                j++;
            }else if(m.size()==k){
                ans=max(ans,j-i);
                m[s[j]]++;
                j++;
            }else{
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
