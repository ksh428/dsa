Node* findIntersection(Node* head1, Node* head2)
{
    Node* i=head1;
    Node* j=head2;
    Node* head=NULL,*curr=NULL;
    while(i and j){
        if(i->data==j->data){
            if(head==NULL){
                Node* t=new Node(i->data);
                head=t;
                curr=t;
            }else{
                Node* t=new Node(i->data);
                curr->next=t;
                curr=curr->next;
            }
            i=i->next;
            j=j->next;
        }else{
            if(i->data<j->data){
                i=i->next;
            }else j=j->next;
        }
    }
    return head;
}
