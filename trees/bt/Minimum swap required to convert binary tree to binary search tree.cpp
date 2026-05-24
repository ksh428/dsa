
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>inorder;
void dfs(vector<int>a,int i,int n){
      if(i>=n) return;
      dfs(a,2*i+1,n);
      inorder.push_back(a[i]);
      dfs(a,2*i+2,n);
}
int getmin(vector<int>nums){
    int c=0;
    int n=nums.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++) m[nums[i]]=i;
    vector<int>a=nums;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]!=nums[i]){
            c++;
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
/*
the inorder of bst will be sorted , so just find the inorder of this bt and
find the min swaps req to sort thisarray
*/

void solve() {
      vector<int>a{};
      int n=a.size();
      dfs(a,0,n);
      cout<<getmin(inorder)<<endl;
}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
