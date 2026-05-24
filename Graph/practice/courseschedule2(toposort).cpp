//https://leetcode.com/problems/course-schedule-ii/


///FOR TOPOSORT GRAPH MUST BE DAG...../////

//FOR TOPOSORT WE CAN ALSO USE KAHNS ALGO...

class Solution {
    void dfs(vector<vector<int>>&adj,int i,vector<bool>&visited,stack<int>&st)
    {
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]==false){
                dfs(adj,j,visited,st);
            }
        }
        st.push(i);
    }

bool iscycleutil(vector<vector<int>>& adj,vector<int> visited,int curr)
{
    if(visited[curr]==true) return true;
    visited[curr]=true;
    bool flag=false;
    for(int j=0;j<adj[curr].size();j++){
        flag=iscycleutil(adj,visited,adj[curr][j]);
        if(flag==true) return true;
    }
    return false;

}


bool iscycle(int numCourses,vector<vector<int>>&adj){
    vector<bool>visited(v,false);
    bool flag=true;
    for(int i=0;i<v;i++){
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            flag=iscycleutil(adj,visited,adj[i][j]);
            if(flag==true) return true;
        }
        visited[i]=false;
    }
    return false;


}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);//n=numCourses
        //form adj matrix
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisited[i][0]);//DIRECTED GRAPH
        }
        //check cycle
        vector<int>ans;
        if(iscyclic(numCourses,adj)){
            return ans;
        }
        //find toposort
        stack<int>st;
        vector<bool>visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(adj,i,visited,st);
            }
        }


        ///
        int dist[n];
        while(!st.empty()){

        }
        while(!st.empty()){
            ans.push_back(st.top);
            st.pop();
        }
        return ans;

    }
};
