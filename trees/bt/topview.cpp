/////GOOD.
// C++ program to print top
// view of binary tree

#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node
{
	Node * left;
	Node* right;
	int hd;
	int data;
};

// function to create a new node
Node* newNode(int key)
{
	Node* node=new Node();
	node->left = node->right = NULL;
	node->data=key;
	return node;
}

// function should print the topView of
// the binary tree
void topview(Node* root)
{
    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        Node* t=q.front().first;
        int h=q.front().second;
        q.pop();
        if(m[h]==0) m[h]=t->data;
        if(t->left) q.push({t->left,h-1});
        if(t->right) q.push({t->right,h+1});

    }
    for(auto it:m) cout<<it.second<<" ";


}

// Driver Program to test above functions
int main()
{
	/* Create following Binary Tree
			1
		/ \
		2 3
		\
			4
			\
			5
			\
				6*/
Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout<<"Following are nodes in top view of Binary Tree\n";
	topview(root);
	return 0;
}
/* This code is contributed by Niteesh Kumar */
