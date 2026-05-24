//delete a node from bst

#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node * left;
    nnode* right;
};
node* Delete(node* root,int val)
{
    if(root==NULL) return NULL;
    else if(root->data>val) root->left=Delete(root->left,val);//update the root of left and right after deletion so we store them
    else if(root->data<val) root->right=Delete(root->right,val);
    else{
        //found
        //case1
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            return root;
        }else if(root->left==NULL){
            node* temp=root;
            root=root->right;
            delete temp;
            return root;

        }else if(root->right==NULL){
            node* temp=root;
            root=root->left;
            delete temp;
            return root;

        }else{
            node* temp=findmin(root->right);// find the min in right subtree
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }

    }

}
node* findmin(bstNode* root)
{   if(root==NULL) return -1;

    bstNode* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;

}

int main()
{
    node* root;

    root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,0);
    cout<<isbst(root);
}
