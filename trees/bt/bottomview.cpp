
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
void bottomview(Node* root)
{
	if(!root) return NULL;
	map<int,int>m;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()){
	    int curr=q.front().first;
	    int currh=q.front().second;
	    q.pop();
	    m[currh]=curr->data;
	    if(curr->left) q.push({curr->left,currh-1});
	    if(curr->right) q.push({curr->right,currh+1});


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
	bottomview(root);
	return 0;
}
/* This code is contributed by Niteesh Kumar */
