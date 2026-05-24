class Solution{
public:
    string printMinNumberForPattern(string s){
        // code here
        stack<int>st;
        string ans="";
        int num=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='D'){
                st.push(num);
                num++;
            }else{
                st.push(num);
                num++;
                while(!st.empty()){
                    ans+=st.top()+'0';
                    st.pop();
                }

            }
        }
        st.push(num);//for the extra char at the end
        while(!st.empty()){
            ans+=st.top()+'0';
            st.pop();
        }
        return ans;
    }
};

