//do the DEQUEUE SOLN



//TC: NLOGN
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            //2.push ele in pq
            //3. check if valid win is formed and store ans
            //1. remove redundant elements
            //before inserting an elelemnt check whether the already highest is i the valid range of curr window
            //if yes then no problem else continue popping until valid
            while(!pq.empty() && pq.top().second<=i-k){
                //pop the top until valid
                pq.pop();
            }
            pq.push({nums[i],i});
            if(i>=k-1){
                //valid window is formed
                ans.push_back(pq.top().first);
            }

        }
        return ans;
    }
};
//USING STACK(NEXT GREATER ELE)  O(n)



#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int>st;
    int k=;
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        if(st.empty()) st.push(i);
        else if(arr[i]<=arr[st.top()]) st.push(i);
        else{
            while(!st.empty() and  arr[i]>arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
   for(int &x:ans){
       if(x==-1) x=n;
   }
   int j=0;
   for(int i=0;i<=n-k;i++){
       if(j<i) j=i;
       while(ans[j]<i+k){
           j=ans[j];
       }
       cout<<arr[j]<<" ";
   }
}

