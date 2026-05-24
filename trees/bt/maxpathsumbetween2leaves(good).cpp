class Solution {
public:
    int solve(Node* root,int &res){
        if(!root) return 0;
        if(!root->left and !root->right){
            return root->data;
        }
        int lv=solve(root->left,res);
        int rv=solve(root->right,res);
        if(root->left and root->right){
            res=max(res,lv+rv+root->data);
            return max(lv,rv)+root->data;
         }
            if(root->left) return lv+root->data;
            else return rv+root->data;

    }
    int maxPathSum(Node* root)
    {
        int res=INT_MIN;
        int val=solve(root,res);
        if(res==INT_MIN) return val; //corner case
        else return res;
    }
};
