class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(!x) return NULL;
        if(x->right!=NULL){
            Node* t=x->right;
            while(t->left!=NULL) t=t->left;
            return t;
        }else{
            Node* ancestor=root;
            Node* succ=NULL;
            while(ancestor!=x){
                if(x->data<ancestor->data){
                    succ=ancestor;
                    ancestor=ancestor->left;
                }else{
                    ancestor=ancestor->right;
                }
            }
            return succ;
        }
    }
};

