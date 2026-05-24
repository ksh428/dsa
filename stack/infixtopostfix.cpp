//both inf o pre and post
//but not working



class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int precedence(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' or ch=='/') return 2;
        else if(ch=='+' or ch=='-') return 1;
        else return -1;
    }
    string infixToPostfix(string s)
    {
        int n=s.size();
        stack<char>st;
        string ans;
        for(int i=0;i<n;i++){
            if((s[i]>='a' and s[i]<='z') or(s[i]>='A' and s[i]<='Z') or(s[i]>='0' and s[i]<='9')){
                ans+=s[i];
            }else if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                while(!st.empty() and st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }else{
                //operator
                while(!st.empty() and precedence(s[i])<precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
