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
bool checkproperty(node* root)
{
    if(root==NULL) return false;
    if(root->left==NULL || root->right==NULL) return true;
    if(root->left!=NULL) int ldata=root->left->data;
    if(root->right!=NULL)  int rdata=root->right->data;
    if(root->data==(ldata+rdata) && checkproperty(root->left) && checkproperty(root->right))
        return true;
    else return false;


}

int main()
{
    node* root;

    root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,0);




