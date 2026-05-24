class Solution {
public:
    int n;
    int i=0;
    TreeNode* solve(vector<int>p,int l,int r){
        if(i>=n) return NULL;
        int val=p[i];
        if(val<l or val>r) return NULL;
        TreeNode* curr=new TreeNode(val);
        i++;
        curr->left=solve(p,l,val);
        curr->right=solve(p,val,r);
        return curr;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n=preorder.size();
        int l=INT_MIN;
        int r=INT_MAX;
        return solve(preorder,l,r);
    }
};
//on(n)
