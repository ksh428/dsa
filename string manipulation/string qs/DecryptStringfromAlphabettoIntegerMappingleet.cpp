
class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        for(int i=0;i<s.size();){
            if(i+2<s.size() && s[i+2]=='#'){
                int no=(s[i]-'0')*10+(s[i+1]-'0');
                char req='a'+no-1;
                ans+=req;
                i+=3;
            }else{
                char req='a'+s[i]-'0'-1;
                ans+=req;
                i++;
            }
        }
        return ans;


    }
};
