
int findparent(int u, vector<int>&parent) {
	if (parent[u] == u) return u;
	return parent[u] = findparent(parent[u], parent);
}
void unionn(int u, int v, vector<int>&parent, vector<int>&rank)
{
	u = findparent(u, parent);
	v = findparent(v, parent);
	if (rank[u] > rank[v]) {
		parent[v] = u;

	} else if (rank[u] < rank[v]) {
		parent[u] = v;

	} else {
		parent[u] = v;
		rank[v]++;
	}
}
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	vector<int>ans;
    //similar to reunion of 1s instead of using index we will use cell no
    vector<int>parent(n*m);
	for (int i = 0; i < n*m; i++) parent[i] = -1;
	vector<int>rank(n*m, 0);
    int c=0;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    for(auto it:q){
        int x=it[0];
        int y=it[1];
        int cellno=x*m+y;
        parent[cellno]=cellno;
        rank[cellno]=1;
        c++;
        for(int i=0;i<4;i++){
            int tx=x+dx[i];
            int ty=y+dy[i];
            int newcellno=tx*m+ty;
            if(tx<0 or ty<0 or tx>=n or ty>=m or parent[newcellno]==-1){
                continue;
            }
            if(findparent(cellno,parent)!=findparent(newcellno,parent)){
                unionn(cellno,newcellno,parent,rank);
                c--;
            }
        }
        ans.push_back(c);
    }
    return ans;
}
