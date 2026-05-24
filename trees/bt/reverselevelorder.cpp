

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
void levelorder(node* root) //tc->o(n)
{
    if(root==NULL) cout<<"empty" ;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
        q.pop();
    }
}

void reverselevelorder(node* root)
{
     if(root==NULL) cout<<"empty" ;
    queue<node*>q;
    stack<int>s;//could also use stack instead

    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        s.push(curr->data);

        if(curr->right!=NULL) q.push(curr->left);
        if(curr->left!=NULL) q.push(curr->right);
        q.pop();
    }

    while(!s.empty()) {cout<<s.top();
    s.pop();
    }

}

int main()
{
    /*node* root;

    root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,0);  */




}
