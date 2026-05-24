//https://www.codingninjas.com/codestudio/problems/roots-of-the-tree-having-minimum-height_1235193?leftPanelTab=0


#include<bits/stdc++.h>
//the ans can atmost be 2 (if length of longest path is even)else its 1
//so start bfs from leaves and at the end we would be left with 1/2 leaf nodes in the queue
vector<int> minHeightRoots(vector<vector<int>> &edges)
{
    vector<int>ans;
    queue<int>q;
    int n=edges.size()+1;
    vector<int>adj[n+1];
    int in[n+1];
     if (n == 1)
    {
        vector<int> ans(1, 1);
        return ans;
    }
    memset(in,0,sizeof(in));
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
        in[it[0]]++;
        in[it[1]]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==1) q.push(i);//leaves
    }
    int sz=n;
    while(sz>2){
        int m=q.size();
        sz-=m;
        for(int i=0;i<m;i++){
            int curr=q.front();
            q.pop();
            for(int j:adj[curr]){
                in[j]--;
                if(in[j]==1) q.push(j);
            }
        }
    }
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
