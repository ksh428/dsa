 public:
    Node* reverse(Node* head){
        if(head->next==NULL or head==NULL) return head;
        Node* nhead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return nhead;
    }
    Node* addOne(Node *head)
    {
        Node* nhead=reverse(head);
        if(nhead->data!=9){
            nhead->data++;
            return reverse(nhead);
        }
        Node* curr=nhead;
        Node* prev=NULL;
        while( curr!=NULL and curr->data==9){
            curr->data=0;
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL){
            Node* newn=new Node(1);
            prev->next=newn;

        }else curr->data++;
        return reverse(nhead);
    }
