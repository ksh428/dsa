#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void dfs(int i,vector<int>&vis,stack<int>st){
      vis[i]=1;
      for(int j:adj[i]){
            if(!vis[j]){
                  dfs(j,vis,st);
            }
      }
      st.push(i);
}

void solve() {
      stack<int>st;
      for(int i=0;i<n;i++){
            if(!vis[i]){
                  dfs(i,vis,st);
            }
      }
      while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
      }


}


