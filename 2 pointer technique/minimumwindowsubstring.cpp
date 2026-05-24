//VV GODD WATCH THE VIDEO

class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        unordered_map<char,int>mp2;
        for(char c:t) mp2[c]++;
        int mct=0,dmct=t.size();//dmct:desired match count
        unordered_map<char,int>mp1;
        int i=0,j=0;
        while(1){
            bool f1=0,f2=0;
            //acquire
            while(i<s.size() and mct<dmct){

                mp1[s[i]]++;
                //check for usefulness
                if(mp1[s[i]]<=mp2[s[i]]){
                    mct++;
                }
                f1=1;
                i++;
            }
             //collect ans and release
            while(j<i and mct==dmct){
                string pans=s.substr(j,i-j);
                if(ans.size()==0 or pans.size()<ans.size()){
                    ans=pans;
                }
                if(mp1[s[j]]==1) mp1.erase(s[j]);
                else mp1[s[j]]--;
                if(mp1[s[j]]<mp2[s[j]]) mct--;
                f2=1;
                j++;
            }
            if(f1==0 and f2==0) break;
        }
        return ans;
    }

};
