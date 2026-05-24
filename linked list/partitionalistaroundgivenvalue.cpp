
struct Node* partition(struct Node* head, int x) {
    // code here
    Node* lf=NULL,*ll=NULL,*ef=NULL,*el=NULL,*mf=NULL,*ml=NULL;
    Node* t=head;
    while(t){
        if(t->data<x){
            if(lf==NULL){
                lf=ll=t;
            }else{
                ll->next=t;
                ll=t;
            }
        }else if(t->data==x){
            if(ef==NULL) ef=el=t;
            else{
                el->next=t;
                el=t;
            }
        }else{
            if(mf==NULL) mf=ml=t;
            else{
                ml->next=t;
                ml=t;
            }
        }

        t=t->next;
    }
     if(ml!=NULL) ml->next=NULL;
        if(lf==NULL){
            if(ef==NULL) return mf;
            el->next=mf;
            return ef;
        }
        if(ef==NULL){
            ll->next=mf;
            return lf;
        }
        ll->next=ef;
        el->next=mf;
        return lf;
}
