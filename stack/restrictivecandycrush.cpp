
class Solution{
    public:
    string Reduced_String(int k,string s){
        if(k==1) return "";
        int n=s.size();
        string ans="";
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push({s[i],1});

            else if(s[i]==st.top().first){
                st.push({s[i],st.top().second+1});
                if(st.top().second==k){
                    int x=k;
                    while(x){
                        st.pop();
                        x--;
                    }
                }
            }else{
                st.push({s[i],1});
            }
        }
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};
