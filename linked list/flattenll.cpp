Node* merge(Node* a,Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* ans=NULL;
    if(a->data<b->data){
        ans=a;
        ans->bottom=merge(a->bottom,b);
    }else{
        ans=b;
        ans->bottom=merge(a,b->bottom);
    }

    return ans;
}

Node *flatten(Node *root)
{
   if(!root or !root->next) return root;
   Node* r=flatten(root->next);
   return merge(root,r);
}
