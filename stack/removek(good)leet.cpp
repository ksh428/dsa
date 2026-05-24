class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        stack<char>st;
        for(char c:s){
            while(!st.empty() and c<st.top() and k>0){
                st.pop();
                k--;
            }
            if(!st.empty() or c!='0') st.push(c);
        }
        while(!st.empty() and k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            s[n-1]=st.top();
            st.pop();
            n--;
        }
        return s.substr(n);
    }
};
