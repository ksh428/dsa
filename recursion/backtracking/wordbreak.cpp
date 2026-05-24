class Solution{
public:
vector<string>res;
    void solve(string s,unordered_set<string>st,string ans){
        if(s.size()==0){
            ans.pop_back();
            res.push_back(ans);
            return;
        }
        for(int i=0;i<s.size();i++){
            string t=s.substr(0,i+1);
            if(st.find(t)!=st.end()){
                string rem=s.substr(i+1);
                solve(rem,st,ans+t+" ");
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& d, string s)
    {
        unordered_set<string>st(d.begin(),d.end());
        solve(s,st,"");
        return res;
    }
};
