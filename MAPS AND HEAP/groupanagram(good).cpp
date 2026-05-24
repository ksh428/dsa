class Solution {
public:
    #define max 256
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        //just store the freq maps and the corresp string that follow the frequency map
        map<map<char,int>,vector<string>>bigm;
        for(string s:strs){
            map<char,int>fm;
            for(char c:s) fm[c]++;
            if(bigm.find(fm)!=bigm.end()){
                bigm[fm].push_back(s);
            }else{
                vector<string>temp;
                temp.push_back(s);
                bigm[fm]=temp;
            }
        }
        for(auto it:bigm){
            ans.push_back(it.second);
        }
        return ans;
    }
};
