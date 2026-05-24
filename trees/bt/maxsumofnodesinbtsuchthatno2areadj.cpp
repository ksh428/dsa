

#include <bits/stdc++.h>

using namespace std;

unordered_map<Node*,int>dp; //contains the ans from the node

int fun(Node* root){
    if(!root) return 0;
    if(dp[root]) return dp[root];//memoisation
    int incl=root->data;
    if(root->left){
        incl+=fun(root->left->left);
        incl+=fun(root->left->right);
    }
    if(root->right){
        incl+=fun(root->right->right);
        incl+=fun(root->right->left);
    }
    int excl=fun(root->left)+fun(root->right);
    dp[root]=max(excl,incl);
    return dp[root];

}

int main()
{

}

