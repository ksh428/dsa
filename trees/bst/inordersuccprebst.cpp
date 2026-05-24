//inorder succesor and pred. in bst
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node* right;
};

void presuc(node* root,node*& pre,node*& suc,int val)
{
    if(root==NULL) return;
    if(root->data==val){
            if(root->left!=NULL){
                node* temp=root->left;
                while(temp->right) temp=temp->right;
                    pre=temp;
            }
        if(root->right!=NULL){
            node* temp=root->right;
            while(temp->left) temp=temp->left;
            suc= temp;
        }
        return;
    }
    if(root->data>val){
            suc=root;
        presuc(root->left,pre,suc,val);
    }
    if(root->data<val){
        pre=root;
        presuc(root->right,pre,suc,val);
    }

}
int main()
{
    node* pre=NULL;
    node* suc=NULL;
    presuc(root,pre,suc,60);
    if(pre!=NULL) cout<<pre->data<<" ";
    else cout<<"no pre";
}
