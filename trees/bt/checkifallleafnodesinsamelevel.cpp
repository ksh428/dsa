class Solution{
  public:
  int ans;
  int inlvl=-1;
    void solve(Node* root,int currlvl){
        if(!root) return;
        if(!root->left and !root->right){
            if(inlvl==-1){
                inlvl=currlvl;
            }else if(inlvl!=currlvl) ans=0;
            else return;
        }
        solve(root->left,currlvl+1);
        solve(root->right,currlvl+1);
    }
    bool check(Node *root)
    {
        ans=1;
        inlvl=-1;
        solve(root,0);
        return ans;

    }
};
