
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   vector<int>ans;
   queue<Node*>q;
   q.push(root);
   if(!root) return ans;
   while(!q.empty()){
       Node* curr=q.front();
       q.pop();
       while(curr){
           if(curr->left) q.push(curr->left);
           ans.push_back(curr->data);
           curr=curr->right;
       }
   }
   return ans;

}
