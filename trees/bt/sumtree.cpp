/*
Write a function that returns true if the given Binary Tree is SumTree else false.
A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree.
An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.
*/


/*
Given a binary tree, write a function that returns true if the tree satisfies below property.
For every node, data value must be equal to sum of data values in left and right children.
 Consider data value as 0 for NULL children. Below tree is an example
*/

#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node * left;
    node* right;
};
node* create(int val){
    node*  temp=new node();
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insert(node* root,int val){
    if(root==NULL){
        //empty tree
        root=create(val);
    }else if(root->data>=val){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}
int findsum(node* root)
{
    if(root==NULL) return 0;
    return findsum(root->left) +root->data +findsum(root->right)

}
bool checksumtree(node* root)   //o(n^2)
{
    if(root==NULL || (root->left==NULL && root->right==NULL) ) return true;
    if(root->data ==findsum(root->left)+findsum(root->right) && checksumtree(root->left) && checksumtree(root->right))
        return true;
    else return false;

}
//better soln o(n)
class Solution
{
    public:
    int f=1;
    int solve(Node* root){
        if(!root) return 0;
        if(!root->left and !root->right) return root->data;
        int l,r;
        if(f==0) return 0;
        l=solve(root->left);r=solve(root->right);
        if(root->data!=l+r) f=0;
        else return l+r+root->data;//return the sum of the subtree starting from  root
    }

    bool isSumTree(Node* root)
    {
         f=1;
         solve(root);
         return f;

    }
};

int main()
{
    node* root;

    root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,0);




}
