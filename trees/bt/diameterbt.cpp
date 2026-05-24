//diameter of binary tree
#include <bits/stdc++.h>
//DIAMETER IS NOTHING BUT MAX VALUE OF LEFT HEGIHT AND ROGHT HEIGHT AT EACH NODE

// o(n^2)
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
int height(node* root)
{
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
int diameter(node* root) //worst case-o(n^2) avg case-o(nlogn)
{
    if(root==NULL) return 0;
    //there are 3 otions review them by taking examples..
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=;diameter(root->right);
    return max(op1,max(op2,op3));
}
//on(n):

 int diameter(struct node* root)
{
	int h=0;

	return solve(root,h);
}

int solve(node* root,int &h){
   if(!root){
       h=0;
       return 0;
   }
   int lh=0;
   int rh=0;
   int ld=solve(root->left,lh);
   int rd=solve(root->right,rh);
   h=max(lh,rh)+1;
   return max({ld,rd,lh+rh});
}



int main()
{
    node* root;

    root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,0);
}
