//adjacency list representation...
#include<bits/stdc++.h>
using namespace std;
struct listnode{
    int vertexno;
    struct listnode* next;

};

struct Graph{
    int V;
    int E;
    struct listnode* adj;
};

Graph* adjListofgraph(){
    int i,x,y;
    struct listnode* temp,*t;
    struct Graph* G;
    G=(struct Graph*)malloc(sizeof(struct Graph));
    cout<<"Enter no of vertices and edges";
    cin>>&G->V>>&G->E;
    G->adj=(struct listnode*)malloc(G->V*sizeof(struct listnode));
    for(i=0;i<G->V;i++){
        G->adj[i]->vertexno=i;
        G->adj[i]->next=G->adj[i];
    }
    for(i=0;i<G->E;i++){
        cout<<"enter edge source node and dest node";
        cin>>x>>y;
        temp=(struct listnode*)malloc(sizeof(listnode));
        temp->vertexno=y;
        temp->next=G->adj[x];
        t=G->adj[x];
        while(t->next!=G->adj[x]){
            t=t->next;
        }
        t->next=temp;
    }
    return G;
}
int main()
{

}
