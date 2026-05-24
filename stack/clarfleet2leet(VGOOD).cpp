
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& a) {
        int n=a.size();
        vector<double>ans(n,-1);
        stack<int>st;//store index of cars
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and a[st.top()][1]>=a[i][1]) st.pop();//remove all cars having speed >= me
            while(!st.empty()){
                double coltime=(double)(a[st.top()][0]-a[i][0])/(double)(a[i][1]-a[st.top()][1]);
                if(coltime<=ans[st.top()] or ans[st.top()]==-1){//cant colide anymore else continue
                    ans[i]=coltime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
