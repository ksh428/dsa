/*Complete the function below
Node is as follows:
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

// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1,Node *root2)
{
    if(!root1 && !root2) return true; //empty or reached end withput any problem
    if(!root1 || !root2) return false; //unequal no of nodes
    if(root1->data !=root2->data) return false;
    bool a=isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);//no swappping req ASSUME
    bool b=isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);//swapping req ASUME

    return a||b;
}
