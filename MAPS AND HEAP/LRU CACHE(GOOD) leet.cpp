class LRUCache {
public:
    //always add a node next to head it will become the most recently used node
    //for getting the last recently used node delete the node prev to tail
    struct node{
        int key;
        int val;
        node* next;
        node* prev;
        node(int k,int v){
            key=k;
            val=v;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int c;
    unordered_map<int,node*>m;
    LRUCache(int cap) {
        c=cap;
        head->next=tail;
        tail->prev=head;
    }

    int get(int k) {
        if(m.find(k)!=m.end()){
            node* res=m[k];
            int ans=res->val;
            m.erase(k);
            deletenode(res);
            addnode(res);
            m[k]=head->next;
            return ans;
        }
        return -1;
    }
    void addnode(node * curr){
        node* t=head->next;
        curr->next=t;
        curr->prev=head;
        head->next=curr;
        t->prev=curr;
    }
    void deletenode(node* curr){
        node* dprev=curr->prev;
        node* dnext=curr->next;
        dprev->next=dnext;
        dnext->prev=dprev;
    }

    void put(int k, int v) {
        if(m.find(k)!=m.end()){
            node* res=m[k];
            deletenode(res);
            m.erase(k);
        }
        if(m.size()==c){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(k,v));
        m[k]=head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
