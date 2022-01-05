#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


typedef struct TreeNode
{
	int value;
	struct TreeNode *left, *right;
}node;



// create a new node
node* getNewNode(int value) {
	node *new_node = new node;
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
/// create the tree
node *createTree() {
	node *root = getNewNode(10);
	root->left = getNewNode(5);
	root->right = getNewNode(50);
	root->left->left = getNewNode(1);
	root->right->left = getNewNode(40);
	root->right->right = getNewNode(100);
	return root;
}


//assuming root lies in the given range
int countBST(node *ptr, int var1, int var2)
{


	if (ptr == NULL)
		return 0;

	int rootcount = 0;
	if (ptr->value >= var1 && ptr->value <= var2)
	{
		rootcount = 1;
	}
	int leftcount = countBST(ptr->left, var1, var2);
	int rightcount = countBST(ptr->right, var1, var2);
	int totalcount = rootcount + leftcount + rightcount;
	return totalcount;

}


int main()
{
	node *root = NULL;
	root = createTree();
	int var1 = 5, var2 = 45;
	int sum = countBST(root, var1, var2);
	cout << "Count of nodes:" << sum;
	return 0;

}


