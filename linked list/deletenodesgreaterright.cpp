class Solution
{
    public:
     struct Node* reverse(struct Node *head)
    {
        if(head->next==NULL or head==NULL) return head;
        Node* nhead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return nhead;
    }

    Node *compute(Node *head)
    {
        // your code goes here
        Node* nhead=reverse(head);
        Node* prev=nhead,*curr=nhead;
        int c=nhead->data;
        curr=curr->next;
        while(curr){
            if(curr->data>=c){
                c=curr->data;
                prev=curr;
                curr=curr->next;
            }else{
                prev->next=curr->next;
                curr->next=NULL;
                delete curr->next;
                curr=prev->next;
            }
        }
        nhead=reverse(nhead);
        return nhead;

    }

};


