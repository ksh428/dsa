class Solution {
public:
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
    int regionsBySlashes(vector<string>& a) {
        int n=a.size();
        int dots=n+1;
        vector<int>parent(dots*dots);
        for (int i = 0; i < dots*dots; i++) parent[i] = i;
        vector<int>rank(dots*dots, 1);
        int ans=1;
        //mark boundary
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0 or j==0 or i==n or j==n){
                    int cellno=i*dots+j;
                    unionn(0,cellno,parent,rank);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='/'){
                    int cell1=i*dots+j+1;
                    int cell2=(i+1)*dots+j;
                    if(findparent(cell1,parent)!=findparent(cell2,parent)){
                        unionn(cell1,cell2,parent,rank);
                    }else ans++;
                }else if(a[i][j]=='\\'){
                    int cell1=i*dots+j;
                    int cell2=(i+1)*dots+j+1;
                    if(findparent(cell1,parent)!=findparent(cell2,parent)){
                        unionn(cell1,cell2,parent,rank);
                    }else ans++;
                }else{
                    continue;
                }
            }
        }
        return ans;

    }
};
