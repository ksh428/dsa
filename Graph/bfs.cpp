#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int>*adj;
public:
    Graph(int V);
    void addedge(int v,int u);
    void BFS(int s);
};
Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}
void Graph::addedge(int v,int u)
{
    adj[v].push_back(u);

}
void Graph::BFS(int s)
{
    bool * visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
            s=q.front();
        cout<<q.front();
        q.pop();
        for(auto it=adj[s].begin();it!=adj[s].end();it++){
            if(visited[*it]==false){
                visited[*it]=true;
                q.push(*it);
            }
        }
    }


}

int main()
{
     Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;

}
