// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;

void dfs(int a[],int n,vector<int>&v,int i){
      if(i>=n) return;
      dfs(a,n,v,2*i+1);
      v.push_back(a[i]);
      dfs(a,n,v,2*i+2);
}

int minSwaps(vector<int>&nums)
{
    int c=0;
    int n=nums.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++) m[nums[i]]=i;
    vector<int>a=nums;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]!=nums[i]){
           int ele1=nums[i];
           int idx=m[a[i]];
           m[nums[i]]=idx;
           m[nums[idx]]=i;
          // c++;
           swap(ele1,nums[idx]);
        }
    }
    return c;
}

// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
      vector<int>v;
      dfs(a,n,v,0);
      cout<<minSwaps(v);
}



