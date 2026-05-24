class Solution{
  public:
 void split(Node*src,Node*&l,Node*&r){
        Node* f=src,*slow=src;
       while(!f and !f->next){
           f=f->next->next;
           slow=slow->next;
       }
        l=src;
        r=slow->next;
        slow->next=NULL;
    }
    Node* merge(Node*a,Node*b){
        if(!a) return b;
        if(!b) return a;
        Node*r=NULL;
        if(a->data<=b->data){
            r=a;
            r->next=merge(a->next,b);
        }else{
            r=b;
            r->next=merge(a,b->next);
        }
        return r;
    }
    void ms(Node*&head){
        if(!head or head->next==NULL) return;
        Node* t=head;
        Node*a;
        Node*b;
        split(t,a,b);
        ms(a);
        ms(b);
        head=merge(a,b);
    }
    Node* mergeSort(Node* head) {
        ms(head);
        return head;
    }
};
