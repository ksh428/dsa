void dfs(Node* root,unordered_set<int>&s){
    if(!root) return;
    dfs(root->left,s);
    s.insert(root->data);
    dfs(root->right,s);
}
int countPairs(Node* root1, Node* root2, int x)
{
    unordered_set<int>s1,s2;
    dfs(root1,s1);
    dfs(root2,s2);
    int ans=0;
    for(auto it:s1){
        if(s2.find(x-it)!=s2.end()) ans++;
    }
    return ans;
}
