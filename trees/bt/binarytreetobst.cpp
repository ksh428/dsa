class Solution{
  public:
  vector<int>v;
  void dfs(Node* root){
      if(!root) return ;
      dfs(root->left);
      v.push_back(root->data);
      dfs(root->right);
  }
  int i=0;
  void conv(Node* root){
      if(!root) return ;
      conv(root->left);
      root->data=v[i++];
      conv(root->right);
  }
    Node *binaryTreeToBST (Node *root)
    {
        dfs(root);
        sort(v.begin(),v.end());
        conv(root);
        return root;

    }
};
