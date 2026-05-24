class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.size()!=b.size()) return 0;
        if(a==b){
            //there mut be atleat 2 equal letters
            if(set<char>(a.begin(),a.end()).size()<a.size())
                return 1;
            else return false;
        }
        vector<int>diff;
        //intuitive
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff.push_back(i);
        }
        if(diff.size()==2 and a[diff[0]]==b[diff[1]] and a[diff[1]]==b[diff[0]]) return 1;
        else return false;
    }
};
