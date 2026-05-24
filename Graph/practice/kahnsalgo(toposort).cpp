class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int v, vector<int> adj[])
	{
	    queue<int>q;
	    vector<int>indeg(v,0);
	    for(int i=0;i<v;i++){
	        for(int j:adj[i]){
	            indeg[j]++;
	        }
	    }
	    for(int i=0;i<v;i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int curr=q.front();
	        q.pop();
	        ans.push_back(curr);
	        for(auto i:adj[curr]){
	            indeg[i]--;
	            if(indeg[i]==0) q.push(i);
	        }
	    }
	    return ans;


	}
};
