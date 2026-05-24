
class Solution {
public:
    int ans=0;
    bool pal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;

    }
    void solve(string &s,string &p,string &q,int i){
        if(i>=s.size()){
            if(pal(p) and pal(q)){
               int n=p.size();
                int m=q.size();
                ans=max(ans,n*m);

            }
            return;
        }
        solve(s,p,q,i+1);
        p+=s[i];
        solve(s,p,q,i+1);
        p.pop_back();
        q+=s[i];
        solve(s,p,q,i+1);
        q.pop_back();

    }
    int maxProduct(string s) {
        string p="";
        string q="";
        solve(s,p,q,0);
        return ans;
    }
};
