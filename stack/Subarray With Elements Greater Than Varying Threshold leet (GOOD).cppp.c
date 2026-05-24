
class Solution {
public:
    int validSubarraySize(vector<int>& a, int t) {
        int n=a.size();
        stack<int>st;
        vector<int>left(n,-1),right(n,-1);
        //left
        for(int i=0;i<n;i++){
            while(!st.empty() and a[i]<=a[st.top()]){
                st.pop();
            }
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //right
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and a[i]<=a[st.top()]){
                st.pop();
            }
            if(!st.empty())  right[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int li=left[i];
            int ri=(right[i]==-1)?n:right[i];
            int len=ri-li-1;
            if(a[i]>t/len) return len;
        }
        return -1;
    }
};
