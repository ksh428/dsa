class Solution
{
    public:
    //Function to convert binary tree to doubly linked list and return it.
    int first=0;
    void solve(Node* root,Node* &head,Node* &prev){
    if(!root) return;
    solve(root->left,head,prev);
    if(first==0){
        head=root;
        prev=head;
        first++;
    }
    else{
        prev->right=root;
        prev->right->left=prev;//root->left=prev;
        prev=prev->right;
    }
    solve(root->right,head,prev);
}
    Node * bToDLL(Node *root)
    {
        Node* head=NULL;
        Node* prev=NULL;
        solve(root,head,prev);
        return head;
    }
};
