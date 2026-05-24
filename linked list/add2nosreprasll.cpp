class Solution
{
    public:
     struct Node* reverseList(struct Node *head)
    {
        if(head->next==NULL or head==NULL) return head;
        Node* nhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return nhead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverseList(first);
        second=reverseList(second);
        int c=0,s=0;
        Node* temp;
        Node* curr=NULL,*res=NULL;
        while(first!=NULL or second!=NULL){
            s=c+(first?first->data:0)+(second?second->data:0);
            c=(s>=10)?1:0;
            s=s%10;
            temp=new Node(s);
            if(res==NULL) res=temp;
            else curr->next=temp;
            curr=temp;
            if(first) first=first->next;
            if(second) second=second->next;
        }
        if(c){
            temp=new Node(c);
            curr->next=temp;
            curr=temp;
        }
        res=reverseList(res);
        return res;
    }
};

