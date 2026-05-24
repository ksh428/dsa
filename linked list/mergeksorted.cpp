class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge2(Node* a,Node* b){
         Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = merge2(a->next, b);
    }
    else {
        result = b;
        result->next = merge2(a, b->next);
    }
    return (result);
    }

    Node* help(Node* a[],int l,int r){
        if(l==r) return a[l];
        if(l>r) return NULL;
        int m=(l+r)/2;
        Node* resl=help(a,l,m);
        Node* resr=help(a,m+1,r);
        return merge2(resl,resr);
    }
    Node * mergeKLists(Node *a[], int k)
    {
        return help(a,0,k-1);

    }
};

