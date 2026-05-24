
class Solution {
public:
    //watch techdose vdo
    //stack multiset map
    vector<string> findItinerary(vector<vector<string>>& a) {
        map<string,multiset<string>>m;
        vector<string>ans;
        stack<string>st;
        for(auto it:a){
            m[it[0]].insert(it[1]);
        }
        st.push("JFK");
        while(!st.empty()){
            string curr=st.top();
            if(m[curr].size()==0){
                ans.push_back(curr);
                st.pop();
            }else{
                auto dst=m[curr].begin();
                st.push(*dst);
                m[curr].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
