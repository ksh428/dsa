//SEE COPY FOR EXP
class Solution{
public:
    int maxLength(string s){
        int n=s.size();
        int ans=0;
        stack<char>cs;
        stack<int>si;//problem index
        si.push(-1);//imp step
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            {
                cs.push(s[i]);
                si.push(i);

            }else{
                if(!cs.empty() and cs.top()=='('){
                    cs.pop();
                    si.pop();
                    ans=max(ans,i-si.top());
                }else{
                    si.push(i);
                }
            }
        }

        return ans;
    }
};
