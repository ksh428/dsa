class Solution {
    //IN situations where we have toapply dsu on strings we can use some id(int) for it
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n=a.size();
        vector<int>parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        vector<int>rank(n, 0);
        //we will do dsu on account id
        map<string,int>eid;
        int id;
        for(id=0;id<n;id++){
            for(int j=1;j<a[id].size();j++){
                if(eid.find(a[id][j])!=eid.end()){
                    int v1=eid[a[id][j]];
                    int v2=id;
                    unionn(min(v1,v2),max(v2,v1),parent,rank);
                }else{
                    eid[a[id][j]]=id;
                }
            }
        }
        for(int i=0;i<n;i++) cout<<parent[i]<<" ";
        //ok
        map<int,set<string>>mp;
        for(int i=0;i<a.size();i++){
            set<string>curr;
            int p=findparent(i,parent);
            if(p==i){
                string s='0'+a[i][0];
                mp[p].insert(s);
                for(int j=1;j<a[i].size();j++){
                mp[p].insert(a[i][j]);
             }
            }else{
                for(int j=1;j<a[i].size();j++){
                mp[p].insert(a[i][j]);
              }
            }
        }
        vector<vector<string>>v;
        for(auto it:mp){
            vector<string>curr;
            string s=*it.second.begin();
            it.second.erase(it.second.begin());
            s=s.substr(1);
            curr.push_back(s);
            for(auto jt:it.second){
                curr.push_back(jt);
            }
            v.push_back(curr);
        }

        return v;


    }
};
