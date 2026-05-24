class Solution {
public:
    vector<string>ans;
    unordered_set<string>used;
    int inv(string s){
        int n=s.size();
        stack<int>st;
        for(char c:s){
            if(c=='(') st.push(c);
            else if(c==')'){
                if(st.empty() or st.top()!='(') st.push(c);
                else if(st.top()=='(') st.pop();
            }
        }
        return st.size();
    }
    void solve(int a,string s){
        if(a<0) return;
        int n=s.size();
        if(a==0){
            int now=inv(s);//check if the current reeuced string is valid or not
            if(now==0){
                ans.push_back(s);
            }
            return;
        }
        for(int i=0;i<n;i++){//trye removing all possible options
            if(s[i]=='(' or s[i]==')'){
                string l=s.substr(0,i);
                string r=s.substr(i+1);
                string t=l+r;
                if(used.find(t)==used.end()){
                    used.insert(t);
                    solve(a-1,t);
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        int cinv=inv(s);
        solve(cinv,s);
        return ans;

    }
};
