
//iterative
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *prev=NULL,*next=NULL;
        Node* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }

};

//recursive
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(!head or head->next==NULL) return head;
       Node* newhead=reverseList(head->next);
       head->next->next=head;
       head->next=NULL;
       return newhead;
    }

};
