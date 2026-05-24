

#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int>st;
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
    for(int x:ans) cout<<x<< " ";

}
