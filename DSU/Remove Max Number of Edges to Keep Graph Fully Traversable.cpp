
class Solution {
public:
    int findparent(int u, vector<int>&parent) {
	if (parent[u] == u) return u;
	return parent[u] = findparent(parent[u], parent);
}
    void unionn(int u, int v, vector<int>&parent, vector<int>&rank){
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

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parenta(n+1,-1);
        vector<int>ranka(n+1,0);
        vector<int>parentb(n+1,-1);
        vector<int>rankb(n+1,0);
        for(int i=1;i<=n;i++) parenta[i]=i;
        for(int i=1;i<=n;i++) parentb[i]=i;
        set<int>sa,sb;
        int ans=0;
        for(auto it:edges){
            if(it[0]==3){
                int f=0;
                int u=it[1];
                int v=it[2];
                if(findparent(u,parenta)!=findparent(v,parenta)){
                    unionn(u,v,parenta,ranka);
                    sa.insert(u);
                    sa.insert(v);
                    f=1;
                }
                  if(findparent(u,parentb)!=findparent(v,parentb)){
                    unionn(u,v,parentb,rankb);
                    sb.insert(u);
                    sb.insert(v);
                    f=1;
                }
                if(!f) ans++;
            }
        }
        for(auto it:edges){
            int u=it[1];
            int v=it[2];
            if(it[0]==1){
                 if(findparent(u,parenta)!=findparent(v,parenta)){
                    unionn(u,v,parenta,ranka);
                     sa.insert(u);
                    sa.insert(v);
                }else ans++;
            }
            if(it[0]==2){
                 if(findparent(u,parentb)!=findparent(v,parentb)){
                    unionn(u,v,parentb,rankb);
                     sb.insert(u);
                    sb.insert(v);
                }else ans++;
            }
        }
        int f=0;
        for(int i=1;i<=n;i++){
            if(parenta[i]==i) f++;
        }
        if(f>1) return -1;
        for(int i=1;i<=n;i++){
            if(parentb[i]==i) f++;
        }
         if(f>2) return -1;

        return ans;

    }
};
