//SIMILAR TO MST
//IMP////CONVER WELLS INTO EDGES FROM 0 TO I AND THEN APPLY NORMAL KRUSKAL USING UNION FIND
#include<bits/stdc++.h>
struct node{
    int u,v,w;
    node(int a,int b,int c){
        u=a;
        v=b;
        w=c;
    }
};
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
bool comp(node a,node b){
    return a.w<b.w;
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	int ans=0;
    vector<node>edges;
    for(int i=1;i<=n;i++){
        edges.push_back(node(0,i,wells[i-1]));
    }
    for(int i=0;i<k;i++){
        edges.push_back(node(pipes[i][0],pipes[i][1],pipes[i][2]));
    }
    vector<int>parent(n+1);
	for (int i = 0; i <= n; i++) parent[i] = i;
	vector<int>rank(n+1, 0);
    sort(edges.begin(),edges.end(),comp);
    for(auto it:edges){
        if(findparent(it.u,parent)!=findparent(it.v,parent)){
            ans+=it.w;

            unionn(it.u,it.v,parent,rank);
        }
    }
    return ans;
}
