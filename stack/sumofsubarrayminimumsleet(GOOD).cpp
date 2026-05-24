class Solution {
public:
    #define mod 1000000007
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        int ans=0;
        //for every element find the first left and right element wwhich is smaller than it
        stack<int>st;
        vector<int>left(n),right(n);
        for(int i=0;i<n;i++){
            left[i]=i;
            right[i]=n-i-1;
        }
        //rightmost
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                if(a[st.top()]<=a[i]) st.push(i);
                else{
                    while(!st.empty() and a[st.top()]>a[i]){
                        right[st.top()]=i-st.top()-1;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        while(!st.empty()) st.pop();
        //leftmost
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(i);
            else{
                if(a[st.top()]<=a[i]) st.push(i);
                else{
                    while(!st.empty() and a[st.top()]>a[i]){
                        left[st.top()]=st.top()-i-1;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        for(int i=0;i<n;i++) cout<<left[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<right[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
           int l=left[i];
            int r=right[i];
            ans+=(l+1)*(r+1)*a[i];
            ans%=mod;
        }
        return ans;
    }
};
