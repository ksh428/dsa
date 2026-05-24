void appendk(Node* head, int k)
{
    int len=findlen(head);
    Node* tail=head;
    Node* newtail;
    Node* newhead;
    int c=1;
    while(tail->next!=NULL){
        if(c==len-k){
            newtail=tail;
        }
        if(c==len-k+1) newhead=tail;
        tail=tail->next;
        c++;
    }

    newtail->next=NULL;
    tail->next=head;




// Print the updated list
printList(newhead);
}
