class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       if(!head or head->next==NULL or head->next->next==NULL) return;
       Node* o=head;
       Node* e=head->next;
       Node* eh=head->next;
       while(e and e->next){

           o->next=o->next->next;
           e->next=e->next->next;
           o=o->next;
           e=e->next;
       }
       o->next=eh;
    }
};
