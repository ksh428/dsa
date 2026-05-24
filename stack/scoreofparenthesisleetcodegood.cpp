class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int ans=0;
        for(char c:s){
            int val=0;
            if(c=='(') st.push(0);
            else{
                while(st.top()!=0) {
                    val+=st.top();
                    st.pop();

                }
                val=max(1,2*val);
                st.pop();
                st.push(val);

            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
