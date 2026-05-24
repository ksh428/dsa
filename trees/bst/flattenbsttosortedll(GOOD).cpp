// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL)
		cout << curr->data << " ", curr = curr->right;
}

// Function to perform in-order traversal
// recursively
void dfs(node* curr, node*& prev)
{
      if(!curr) return;
      dfs(curr->left,prev);
      prev->right=curr;
      prev->left=NULL;
      prev=curr;
      dfs(curr->right,prev);
}

// Function to flatten binary tree using
// level order traversal
node* flatten(node* root)
{
      node dumm=new node(-1);
      node* prev=dumm;
      dfs(root,prev);
      prev->right=NULL;
      prev->left=NULL;
      return dumm->right;

}

// Driver code
int main()
{
	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	// Calling required function
	print(flatten(root));

	return 0;
}

