
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>v(26,0);
        int start=0;
        int maxcount=0;
        int ans=0;
        for(int end=0;end<n;end++){
            v[s[end]-'A']++;
            //find the maxoccuring char int the current window
            if(v[s[end]-'A']>maxcount) maxcount=v[s[end]-'A'];
            //no of ele left in the window after excluding maxocc ele
            int remele=end-start+1-maxcount;
            if(remele>k){
                //cant take this window
                //slide it fwd
                v[s[start]-'A']--;
                start++;
            }
            ans=max(ans,end-start+1);
        }
        return ans;

    }
};
