class Solution {
public:
    int totalSteps(vector<int>& a) {
        int n=a.size();
        stack<pair<int,int>>st;//element,count
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int c=0;
            while(!st.empty() and a[i]>st.top().first){
                c=max(c+1,st.top().second);//didnt understand this
                st.pop();
            }
            st.push({a[i],c});
            ans=max(ans,c);
        }
        return ans;

    }
};
