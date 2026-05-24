
int evaluatePostfix(string s)
    {
        // Your code here
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9') st.push(s[i]-'0');
            else{
                int v2=st.top();st.pop();
                int v1=st.top();st.pop();
                switch(s[i]){
                    case '*':
                    st.push(v1*v2);
                    break;
                    case '+':
                    st.push(v1+v2);
                    break;
                    case '-':
                    st.push(v1-v2);
                    break;
                    case '/':
                    st.push(v1/v2);
                    break;
                    default:break;
                }
            }
        }
        return st.top();
