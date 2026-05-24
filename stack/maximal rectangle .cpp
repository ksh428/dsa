class Solution {
public:
    //similar to largest rect in histo
    //mxn
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);

        stack<int> mystack;
        for(int i=0;i<n;++i)    //Fill left
        {
            if(mystack.empty())
            {    left[i] = 0;   mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                left[i] = mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }
        while(!mystack.empty()) //Clear stack
            mystack.pop();

        for(int i=n-1;i>=0;--i) //Fill right
        {
            if(mystack.empty())
            {   right[i] = n-1; mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                right[i] = mystack.empty()?n-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        int mx_area = 0;    //Stores max_area
        for(int i=0;i<n;++i)
            mx_area = max(mx_area,heights[i]*(right[i]-left[i]+1));
        return mx_area;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>pref(m,vector<int>(n));
        for(int i=0;i<n;i++) pref[0][i]=a[0][i]-'0';
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='0') pref[i][j]=0;
                else{
                    pref[i][j]=pref[i-1][j]+1;
                }
            }
        }
        int ans=0;
       for(int i=0;i<m;i++){
           ans=max(ans,largestRectangleArea(pref[i]));
       }
        return ans;
    }
};
