
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        if(n==1){
            ans.push_back(new TreeNode(0));
            return ans;
        }
        n--;
        for(int i=1;i<=n;i+=2){//i is no of left child of node n
            vector<TreeNode*>l=allPossibleFBT(i);
            vector<TreeNode*>r=allPossibleFBT(n-i);
            for(auto n1:l){
                for(auto n2:r){
                    TreeNode* curr=new TreeNode(0);
                    curr->left=n1;
                    curr->right=n2;
                    ans.push_back(curr);
                }
            }
        }
        return ans;

    }
};
