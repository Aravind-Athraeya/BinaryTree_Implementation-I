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
node *getNewNode(int value) {
	node *new_node = new node;
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
// create the tree
node *createTree() {
	node *root = getNewNode(15);
	root->left = getNewNode(10);
	root->right = getNewNode(20);
	root->right->left = getNewNode(22);
	root->left->left = getNewNode(6);
	root->left->right = getNewNode(7);
	root->left->right->left = getNewNode(2);
	root->left->right->right = getNewNode(16);
	root->left->right->left->left = getNewNode(0);
	root->left->right->left->right = getNewNode(5);
	root->left->right->right->left = getNewNode(3);
	return root;
}

int minSumPath(node *ptr) {
	if (ptr == NULL)
		return 0;

	int sum = ptr->value;

	int left_sum = minSumPath(ptr->left);
	int right_sum = minSumPath(ptr->right);

	if (left_sum <= right_sum)
		sum += minSumPath(ptr->left);
	else
		sum += minSumPath(ptr->right);

	return sum;
}

int main()
{
	node *root = NULL;
	root = createTree();
	int sum = minSumPath(root);
	cout << "Min Sum :: " << sum;
	cout << endl;
	return 0;
	
}


