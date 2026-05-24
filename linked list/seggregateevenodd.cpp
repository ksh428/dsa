
class Solution{
public:
    Node* divide(int n, Node *head){
        Node* t=head;
        Node *e=NULL;
        Node *eh=NULL;
        Node *o=NULL;
        Node *oh=NULL;
        while(t!=NULL){
            if((t->data)&1){
                if(!oh){
                    oh=t;
                    o=t;
                    t=t->next;
                    o->next=NULL;
                }else{
                    o->next=t;
                    o=t;
                    t=t->next;
                    o->next=NULL;
                }
            }else{
                if(!eh){
                    eh=t;
                    e=t;
                    t=t->next;
                    e->next=NULL;
                }else{
                    e->next=t;
                    e=t;
                    t=t->next;
                    e->next=NULL;
                }
            }
        }

      if(!eh) return oh;
        e->next=oh;
        return eh;
    }
};
