


#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>>adj[1001];

void dfs(int i,vector<int>&vis,stack<int>&st){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j.first]) dfs(j.first,vis,st);
    }
    st.push(i);
}

int main()
{
    int v,e;
    cin>>v>>e;
    int src;
    cin>>src;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    //step1 : do toposort using dfs and stack
    vector<int>vis(v,0);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st);
        }
    }
    //step 2
    vector<int>dis(v,INT_MIN);
    dis[src]=0;
    while(!st.empty()){
        if(dis[st.top()]!=INT_MIN){
            //it can be visited
            for(auto j:adj[st.top()]){
                int w=j.second;
                int v=dis[j.first];
                int u=dis[st.top()];
                if(u+w>v){
                    dis[j.first]=u+w;
                }
            }
        }
        st.pop();
    }
    for(int x:dis){
        if(x!=INT_MIN) cout<<x<<" ";
    }


}
