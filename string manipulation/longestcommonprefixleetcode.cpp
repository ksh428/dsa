class Solution {
public:
    bool possible(int m,vector<string>& strs){
        string s=strs[0].substr(0,m);
        for(int i=1;i<strs.size();i++){
            string s1;
            s1=strs[i].substr(0,m);
            if(s1!=s) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string ans="";
        int minl=201;
        for(auto s:strs){
            if(s.size()<minl) minl=s.size();
        }
        int l=0;
        int r=minl;
        int f=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(possible(m,strs)){
                f=m;
                l=m+1;
            }else r=m-1;
        }
        if(f==0) return ans;
        else return strs[0].substr(0,f);

    }
};

//other soln

class Solution {
public:
    static bool comp(string a,string b){
        return a.size()<=b.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        sort(strs.begin(),strs.end());
        string s1=strs[0];//smallest
        string s2=strs.back();
        int i=0,j=0;
        int c=0;
        while(i<s1.size()){
            if(s1[i]==s2[i]) c++;
            else break;
            i++;
        }
        return s1.substr(0,c);

    }
};
