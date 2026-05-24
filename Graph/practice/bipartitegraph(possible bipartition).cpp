
//FOR BIPARTITE GRAPH ONLY EVEN LENGTH CYCLE SHUD BE PRESENT
//GRAPH COLOURING....
#include <bits/stdc++.h>

//u can also use dfs

using namespace std;

bool isBipartite(int G[][V],int start,vector<int>&color){
    color[start]=1;

    queue<int>q ;
    q.push(start);
    while(!q.empty()){
        int u=q.front();
        if(G[u][u]==1) return false; //self loop
        q.pop();
        for(int i=0;i<V;i++){
            if(G[u][i] && color[i]==-1){
                color[i]=1-color[u];
                q.push(i);
            }else if(G[u][i] && color[i]==color[u]) return false;
        }
    }
    return true;
}

bool bipartiteutil(int G[][V]){ //to handle disconnected graph
     vector<int>color(V,-1);
     for(int i=0;i<V;i++){
         if(color[i]==-1){
             if(isBipartite(G,i,color)==false) return false;
         }
     }
     return true;

}

int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    bipartiteutil(G) ? cout << "Yes" : cout << "No";
    return 0;
}

//POSSIBLE BIPARTITION LEETCODE .


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

    bool isbipartite(vector<vector<int>>&adj,vector<int>&color,int i,int n){
        queue<int>q ;
        q.push(i);
        color[i]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int ele:adj[curr]){
                if(color[ele]==color[curr]) return false;
                if(color[ele]==-1) {
                    color[ele]=1-color[curr];
                    q.push(ele);
                }

            }
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(N+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N+1,-1);
        for(int i=0;i<N+1;i++){
            if(color[i]==-1){
                if(!isbipartite(adj,color,i,N)){
                    return false;

                }
            }
        }
        return true;


    }
}; +
