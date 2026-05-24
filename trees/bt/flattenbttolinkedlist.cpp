//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return ;
        TreeNode* tleft=root->left;
        TreeNode* tright=root->right;
        root->left=NULL;
        flatten(tleft);
        flatten(tright);
        root->right=tleft;
        TreeNode* curr=root;
        while(curr->right!=NULL) curr=curr->right;
        curr->right=tright;
    }
};
