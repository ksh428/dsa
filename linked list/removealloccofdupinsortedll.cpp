class Solution
{
    public:
    Node* removeAllDuplicates(struct Node* head)
    {
        //code here
        if(head==NULL or head->next==NULL) return head;
        int val=head->data;
        if(val!=head->next->data){
            head->next=removeAllDuplicates(head->next);
            return head;
        }else{
            while(head!=NULL and val==head->data) head=head->next;
            return removeAllDuplicates(head);
        }
    }
};
