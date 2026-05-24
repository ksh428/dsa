
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void saveparent(map<TreeNode*,TreeNode*>&m,TreeNode* root){
        if(!root) return;
        if(root->left) m[root->left]=root;//child,parent
        if(root->right) m[root->right]=root;
        saveparent(m,root->left);
        saveparent(m,root->right);
    }
    //we need to maintain a map so that we are able to traverse a nodes parent

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        //traverse similar to graph
        if(!root) return ans;
        map<TreeNode*,TreeNode*>m;
        saveparent(m,root);
        queue<TreeNode*>q;
        q.push(target);
        set<TreeNode*>s;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                s.insert(curr);
                if(k==0) ans.push_back(curr->val);
                if(m[curr]!=NULL and s.find(m[curr])==s.end()) q.push(m[curr]);
                if(curr->left and s.find(curr->left)==s.end()) q.push(curr->left);
                if(curr->right and s.find(curr->right)==s.end()) q.push(curr->right);
            }
            k--;
            if(k<0) break;
        }
        return ans;
    }
};
