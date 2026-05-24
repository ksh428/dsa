

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'

void inorder(Node* root,vector<int>&v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int kthLargest(Node *root, int k)
{
    //Your code here
    vector<int>v;
    inorder(root,v);
    sort(v.rbegin(),v.rend());
    return v[k-1];
}
