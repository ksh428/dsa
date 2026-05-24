
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
//see copy for detailed exp
class Solution {
public:
    map<pair<TreeNode*,pair<int,int>>,int>dp;
    int solve(TreeNode* root,int cam,int parcam){
        if(!root){
            if(cam) return 1e6;
            else return 0;
        }
        if(!root->left and !root->right){
            if(cam) return 1;
            if(parcam) return 0;
            else return 1e6;
        }
        if(dp.find({root,{cam,parcam}})!=dp.end()) return dp[{root,{cam,parcam}}];
        if(cam){
            return dp[{root,{cam,parcam}}]=1+min(solve(root->left,1,1),solve(root->left,0,1))+min(solve(root->right,1,1),solve(root->right,0,1));
        }else{
            if(parcam){//no camera in child
                return dp[{root,{cam,parcam}}]=min(solve(root->left,1,0),solve(root->left,0,0))+min(solve(root->right,1,0),solve(root->right,0,0));
            }else{//force one of the childs to have cam
                int op1=solve(root->left,1,0)+min(solve(root->right,1,0),solve(root->right,0,0));
                int op2=solve(root->right,1,0)+min(solve(root->left,1,0),solve(root->left,0,0));
                return dp[{root,{cam,parcam}}]=min(op1,op2);
            }
        }

    }
    int minCameraCover(TreeNode* root) {
        //memset(dp,-1,sizeof(dp));
        return min(solve(root,1,0),solve(root,0,0));
    }
};
