
#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node * left;
    node* right;
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
void levelorderbst(node* root) //tc->o(n)
{
    if(root==NULL) return ;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr=q.front();
        if(curr){
           cout<<curr->data<<" ";
        while(q.front()!=NULL){ //level
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
            q.pop();
            curr=q.front();
            }
        q.push(NULL);
        }
        q.pop();
    }
}
int findmax(node* root)
{
     if(root==NULL) return -1;
    queue<node*>q;
    int maxi=INT_MIN;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        maxi=max(maxi,curr->data);
       //cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
    return maxi;
}
void insertbst(node* root,int val)
{
    node* newnode=create(val);
     if(root==NULL) cout<<"error";
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        maxi=max(maxi,curr->data);
       //cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();

}
int main()
{
    /*node* root;

    root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,0);  */




}
