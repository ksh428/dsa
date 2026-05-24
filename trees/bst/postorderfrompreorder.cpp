//method 1 :create the tree from preorder and then find postorede
//method 2:

// C++ program for finding postorder
// traversal of BST from preorder traversal
#include <bits/stdc++.h>
using namespace std;

// Function to find postorder traversal from
// preorder traversal.
void findPostOrderUtil(int pre[], int n, int minval,
					int maxval, int& preIndex)
{
    if(preIndex ==n) return;
    if(pre[preIndex]<minval || pre[preIndex]>maxval) return;
    int val=pre[preIndex];
    preIndex++;
    findPostOrderUtil(pre,n,minval,val,preIndex);//L
    findPostOrderUtil(pre,n,val,maxval,preIndex);//R
    cout<<val<<" ";//D

}

// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{
    int ind=0; // will traverse the pre array
    findPostOrderUtil(pre,n,INT_MIN,INT_MAX,ind);


}

// Driver code
int main()
{
	int pre[] = { 40, 30, 35, 80, 100 };

	int n = sizeof(pre) / sizeof(pre[0]);

	// Calling function
	findPostOrder(pre, n);
	return 0;
}

