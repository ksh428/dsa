class Solution {
public:
    int ans=0;
    void solve(TreeNode* root, int mx,int mn){
       if(!root){
           ans=max(ans,mx-mn);
           return;
       }
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        solve(root->left,mx,mn);
        solve(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val,root->val);
        return ans;
    }
};
