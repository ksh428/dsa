class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void solve(Node* root,vector<int>&v){
        if(!root){
            v.push_back(-1);
            return ;
        }
        v.push_back(root->data);
        solve(root->left,v);
        solve(root->right,v);
        return;
    }
    vector<int> serialize(Node *root)
    {
        vector<int>v;
        solve(root,v);
        return v;

    }

    //Function to deserialize a list and construct the tree.

    int curr=0;
    Node * deSerialize(vector<int> &A)
    {
       if(A[curr]==-1){
           curr++;
           return NULL;
       }
       Node* root=new Node(A[curr]);
       curr++;
       root->left=deSerialize(A);
       root->right=deSerialize(A);
       return root;
    }

};
