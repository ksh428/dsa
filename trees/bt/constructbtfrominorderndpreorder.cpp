ode is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

unordered_map<int,int>m;
int idx=0

Node* solve(int in[],int pre[],int l,int u){ //lb and ub will traverse thru the in array
    if(l>u) return NULL;
    Node* curr=new Node(pre[idx++]);
    if(l==u) return curr;
    int pos=m[pre[curr->data]];
    curr->left=solve(in,pre,l,pos-1);
    curr->right=solve(in,pre,pos+1,u);
    return curr;
}

Node* buildTree(int in[],int pre[], int n)
{
    idx=0; // totraverse preorder
    m.clear();
    for(int i=0;i<n;i++) m[in[i]]=i;
    Node* root=solve(in,pre,0,n-1);
    return root;


}
