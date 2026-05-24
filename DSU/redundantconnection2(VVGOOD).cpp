class Solution {
public:
    int findparent(int u, vector<int>&parent) {
	if (parent[u] == u) return u;
	return parent[u] = findparent(parent[u], parent);
}
bool unionn(int u, int v, vector<int>&parent, vector<int>&rank)
{
	u = findparent(u, parent);
	v = findparent(v, parent);
    if(u==v){
        return 1;
    }
	if (rank[u] > rank[v]) {
		parent[v] = u;

	} else if (rank[u] < rank[v]) {
		parent[u] = v;

	} else {
		parent[u] = v;
		rank[v]++;
	}
    return 0;
}
    //there will be atmost 1 cycle
    //if no node has indeg 2 then there must be a cycle
    //we can apply dsu to check which edge causes cycle as it is confirmed that there is a cycle
    //

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        vector<int>rank(n+1,0);
        vector<int>indeg(n+1,-1);
        int bl1=-1,bl2=-1;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(indeg[v]==-1){
                indeg[v]=i;
            }else{
                bl1=i;
                bl2=indeg[v];
                break;
            }
        }
        //1. if there is only cycle and no node with indeg 2
        //then both bl1 and bl2 will be -1
        //2. if only 1 node with deg 2 then both bl1 and bl2 will not be -1
        //3. if both then same as 2
        //first assume that bl1 edge is answ
        for(int i=0;i<n;i++){
            if(i==bl1) continue;
            int u=edges[i][0];
            int v=edges[i][1];
            bool flag=unionn(u,v,parent,rank);
            if(flag){
                if(bl2==-1){
                    return edges[i];
                }else return edges[bl2];
            }
        }
        return edges[bl1];

    }
};
