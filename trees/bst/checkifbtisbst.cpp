
#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node * left;
    nnode* right;
};


/*
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
} */
bool checkbst(node* root,int minval,int maxval) //every element
{
    if(root==NULL) return true;
    if(root->data>minval && root->data<maxval && checkbst(root->left,minval,root->data) && checkbst(root->right,root->data,maxval))
        return true;
    else return false;
}

bool isbst(node * root)
{
    return checkbst(root,INT_MIN,INT_MAX);

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
