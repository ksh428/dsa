
//KRUSKALS ALGO
#include <bits/stdc++.h>
using namespace std;

struct node{
    int u,v,w;
    node(int f,int s,int wt){
        u=f;
        v=s;
        w=wt;
    }
};
bool comp(node a,node b){
    return a.w<b.w;
}

int findpar(int u,vector<int>&par){
    if(u==par[u]) return u;
    return par[u]=findpar(par[u],par);
}
void union(int u,int v,vector<int>&par,vector<int>&rank){
    u=findpar(u);
    v=findpar(v);
    if(rank[u]<rank[v]){
        par[u]=v;
    }else if(rank[v]<rank[u]){
        par[v]=u;
    }else{
        par[v]=u;
        rank[u]++;
    }
}
int main()
{
    int N,m;
    cin>>N>>m;
    vector<node>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    sort(edges.begin(),edges.end(),comp);
    vector<int>parent(N);
    for(int i=0;i<N;i++) parent[i]=i;
    vector<int>rank(N,0);
    int cost=0;
    vector<pair<int,int>>mst;
    for(auto it:edges){
        if(findpar(it.u,parent)!=findpar(it.v,parent)){
            cost+=it.w;
            mst.push_back({it.u,it.v});
            union(it.u,it.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    for(auto it:mst) cout<<it.first<<" "<<it.second<<endl;
}

#include <algorithm>

class UnionFind {
    vector<int> parent;
    vector<int> rank;

    public:
        UnionFind(int n) {

        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        rank.resize(n + 1, 0);
    }

    int find(int x) {
        return (x == parent[x]) ? x : find(parent[x]);
    }

    void Union(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py) {
            return;
        }

        if (rank[px] >= rank[py]) {
            parent[py] = px;
            rank[px] += rank[py];
        }
        else {
            parent[px] = py;
            rank[py] += rank[px];
        }
    }
};

class node
{
    public:
    int node1;
    int node2;
    int cost;

    node(int n1, int n2, int c)
    {
        node1 = n1;
        node2 = n2;
        cost = c;
    }
};

static bool comp(node n1 , node n2)
{
    return n1.cost < n2.cost;
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {

    //  Array/vector to hold the costs.
    vector<node> costs;

    for (int i = 1; i <= n; ++i) {
        node obj(0, i, wells[i - 1]);
        costs.push_back(obj);
    }

    for (int i = 0; i < k; ++i) {
        node obj(pipes[i][0], pipes[i][1], pipes[i][2]);
        costs.push_back(obj);
    }

    //  Sort the array according to the cost.
    sort(costs.begin(), costs.end(), comp);

    int minCost = 0;

    UnionFind uf(n);

    for (auto edge : costs) {

        int rootX = uf.find(edge.node1);
        int rootY = uf.find(edge.node2);

        if (rootX == rootY){
            continue;
        }

        minCost += edge.cost;

        uf.Union(edge.node1, edge.node2);

        // For each union, we connnect one node.
        n--;

        // If all nodes already connected, terminate early.
        if (n == 0) {
            return minCost;
        }
    }

    return minCost;
}
