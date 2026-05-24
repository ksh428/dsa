#include <bits/stdc++.h>

using namespace std;
vector<int>adj[100001];
#define ll long long
void dfs(int i,int &no,vector<int>&vis){
    no++;
    vis[i]=1;
    for(int j:adj[i]){
        if(!vis[j]){
            dfs(j,no,vis);
        }
    }

}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c=0;
    vector<int>vis(n,0);
    vector<int>conn(n);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int no=0;
            dfs(i,no,vis);
            conn[c]=no;
            c++;
        }
    }
    ll totways=n*(n-1)/2;//hc2
    ll notallowed=0;
    for(int i=0;i<c;i++){
        notallowed+=conn[i]*(conn[i]-1)/2;//nc2
    }
    cout<<totways-notallowed;

}
