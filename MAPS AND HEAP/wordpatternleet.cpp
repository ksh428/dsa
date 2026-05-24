class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        int c=0;
        while(ss>>s){
            words.push_back(s);
            c++;
        }

       if(c!=pattern.size()) return false;
        unordered_map<char,string>mp;
        unordered_map<string,bool>used;
        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            if(mp.find(ch)!=mp.end()){
                string with=mp[ch];
                if(with!=words[i]) return false;

            }else{
                if(used.find(words[i])!=used.end()) return false;
                else{
                used[words[i]]=1;
                mp[ch]=words[i];
            }
        }

    }
          return true;
    }
};

