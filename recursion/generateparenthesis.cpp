class Solution {
public:
    vector<string>ans;
    void solve(int o,int c,int n,string &s){
        if(o>n or c>n) return;
        if(o==n and c==n){
            ans.push_back(s);
            return;
        }
        if(o==c){
            s+='(';
            solve(o+1,c,n,s);
            s.pop_back();
        }
        if(o>c){
            s+='(';
            solve(o+1,c,n,s);
            s.pop_back();
            s+=')';
            solve(o,c+1,n,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string asf="";
        solve(0,0,n,asf);
        return ans;
    }
};
