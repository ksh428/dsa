class Solution
{
public:
    void solve(Node* root,Node*&njx){
        if(!root) return;
        solve(root->right,njx);
        root->next=njx;
        njx=root;
        solve(root->left,njx);
    }

    void populateNext(Node *root)
    {
        Node* njx=NULL;
        solve(root,njx);
    }
};
