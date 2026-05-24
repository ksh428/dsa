class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        int c=1;
        if(k==0) return head;
        Node* t=head;
        Node* nhead=NULL;
        Node* prev=NULL;
        while(c!=k){
            t=t->next;
            c++;
        }
        if(t->next==NULL) return head;
        prev=t;
        nhead=t->next;
        t=t->next;
        prev->next=NULL;
        while(t->next!=NULL) t=t->next;
        t->next=head;
        return nhead;
    }
};
