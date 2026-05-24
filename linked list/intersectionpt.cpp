
int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node*,int>m;
    Node* t=head1;
    while(t!=NULL){
        m[t]=1;
        t=t->next;
    }
    Node* t1=head2;
    while(t1!=NULL){
        if(m[t1]!=0) return t1->data;
        t1=t1->next;
    }
    return -1;
}

