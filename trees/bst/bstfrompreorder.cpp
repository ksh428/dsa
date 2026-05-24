
#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node * left;
    nnode* right;
};
node* insert(node* &root,int x)   //o(n^2)
{
    if(root==NULL) return createnode(x);
    if(root->data>x){
        root->left=insert(root->left,x);
    }else root->right=insert(root->right,x);
    return root;
}
int main()
{
    node* root;
    int a[]={8,5,1,7,10,12};
    for(int x:a){
    insert(root,x);
    }
}
