map<Node*,Node*>mp;
  void getpar(Node* root){
      if(!root) return;
      if(root->left) mp[root->left]=root;
      if(root->right) mp[root->right]=root;
      getpar(root->left);
      getpar(root->right);
 }
  Node* temp=NULL;
 void mark(Node* root,int t){
      if(!root) return;
      if(root->data==t) {
          temp=root;
          return;
      }
      mark(root->left,t);
      mark(root->right,t);
  }

Node* kthAncestorBFS(Node *root, int node , int &k)
{
	  getpar(root);
	  mark(root,node);
	  queue<pair<int,Node*>>q;
      while(k>0 and mp.find(temp)!=mp.end()){
            temp=mp[temp];
            k--;
      }
      return (k==0)?temp:NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* parent = kthAncestorBFS(root,node,k);
	if (parent)
		return parent->data;
	else return -1;
}
