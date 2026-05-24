 unordered_map<Node*,int>m;
        while(head){
            if(!m[head]){
                m[head]=1;
                head=head->next;
            }else return 1;
        }
        return 0;



//other method
if(!head) return 0;
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return 1;
        }
        return 0;
