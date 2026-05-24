//fold of ll/ reorder ll
//see copy for exp
int size=0;

void solve(Node* right,int c,Node* &left){
    if(right==NULL) return;
    solve(right->next,c+1,left);
    if(c>size/2){
       Node* temp=left->next;
        right->next=temp;
        left->next=right;
        left=temp;
    }else if(c==size/2) right->next=NULL;

}
int getCount(Node* head)
{
    // Base Case
    if (head == NULL) {
        return 0;
    }
    // Count this node plus the rest of the list
    else {
        return 1 + getCount(head->next);
    }
}
void reorderList(Node* head) {
    size=getCount(head);
    Node*left=head;
    solve(head,0,left);
}
