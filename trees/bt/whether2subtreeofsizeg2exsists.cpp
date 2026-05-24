//Check if a Binary Tree contains duplicate subtrees of size 2 or more

unordered_map<string,int>m;
string solve(Node* root){
    if(!root) return "$";
    string s="";
    if(!root->left && !root->right){
        s= to_string(root->data);
        return s;
    }
    s+=to_string(root->data);
    s+=solve(root->left);
    s+=solve(root->right);
    m[s]++;
    return s;

}
bool dupSub(Node *root)
{
     //your code here
     m.clear();
     solve(root);
     for(auto it:m){
         if(it.second>=2) return true;
     }
     return false;
}
