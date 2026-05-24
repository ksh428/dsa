#include<bits/stdc++.h>
using namespace std;
struct bstNode{
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode* create(int data)
{
    //func to create new node
    bstNode*  newNode=new bstNode();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
bstNode* Insert(bstNode* root,int val){//pass the address of the root.thats why we need pointer to pointer
    if(root==NULL){
        //EMPTY
        root=create(val);

    }else if(root->data>=val){
        root->left=Insert(root->left,val);
    }else{
        root->right=Insert(root->right,val);
    }
    return root;

}
bool search(bstNode* root,int val){
    if(root==NULL) return false;
    else if(root->data==val) return true;
    else{
        if(root->data>val){
            search(root->left,val);
        }else search(root->right,val);

    }

}
int findmax(bstNode* root)//here root is local variable so we can use root instead of curr
{
    if(root==NULL) return -1;
    bstNode* curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr->data;

}
int findmin(bstNode* root)
{   if(root==NULL) return -1;

    bstNode* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr->data;

}
int findheight(bstNode* root)
{
    if(root==NULL) return -1;
    return max(findheight(root->left),findheight(root->right))+1;
}
int main(){
    bstNode* root;
    root=NULL;
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,30);
    int no;
   /* cout<<"enter no to search";
    cin>>no;
    if(search(root,no)) cout<<
        "found";
    else cout<<"not found"; */
        cout<<findmin(root);
        cout<<findheight(root);
}
