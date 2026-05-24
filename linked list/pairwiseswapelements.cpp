class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head)
    {
        if(!head or head->next==NULL) return head;
        Node* r=head->next->next;
        Node* newh=head->next;
        head->next->next=head;
        head->next=pairWiseSwap(r);
        return newh;

    }
};
