
class Solution
{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int a[], int n)
    {
       vector<int>ans(n);
       stack<int>s;
       s.push(0);
       ans[0]=1;
       for(int i=1;i<n;i++){
           while(!s.empty() and a[i]>=a[s.top()]){
               s.pop();
           }
           if(s.empty()) ans[i]=i+1;
           else{
               ans[i]=i-s.top();
           }
           s.push(i);
       }
       return ans;
    }
};
