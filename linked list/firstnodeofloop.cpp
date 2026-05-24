
class Solution {
public:

    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL and f->next!=NULL){
            f=f->next->next;
            s=s->next;
            if(f==s) break;
        }
        if(!f or f->next==NULL) return NULL;
        s=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return f;

    }
};
