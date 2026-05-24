
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int bal=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') bal++;
            else bal--;
            if(bal==0) ans++;
        }
        return ans;


    }
};
