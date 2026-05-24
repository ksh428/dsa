vector<Node*>v;
void dfs(Node* root){
    if(!root) return;
    dfs(root->left);
    v.push_back(root);
    dfs(root->right);
}
Node* solve(int l,int r){
    if(l>r) return NULL;
    int m=(l+r)/2;
    Node* curr=v[m];
    curr->left=solve(l,m-1);
    curr->right=solve(m+1,r);
    return curr;

}
Node* buildBalancedTree(Node* root)
{
    v.clear();
	dfs(root);
	return solve(0,v.size()-1);
}
