Node* sortedMerge(Node* head1, Node* head2)
{
    Node* p1=head1;
    Node* p2=head2;
    Node* dummy=new Node(-1);
    Node* p3=dummy;
    while(p1!=NULL and p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p3=p3->next;
        p1=p1->next;
    }
     while(p2!=NULL){
        p3->next=p2;
        p3=p3->next;
        p2=p2->next;
    }
    return dummy->next;

}
