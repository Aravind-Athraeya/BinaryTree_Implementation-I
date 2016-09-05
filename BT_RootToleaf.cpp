#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
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
// create the tree
node *createTree() {
	node *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->left->right = getNewNode(8);
	root->right->left = getNewNode(5);
	root->right->right = getNewNode(6);
	return root;
}


//assuming root lies in the given range
bool hasPathBST(node *ptr, int sum)
 {
	bool isavailable = false;
	if (ptr == NULL)
	{
		return false;
	}
	

	int xrrot = ptr->value;
	bool pathleft= hasPathBST(ptr->left, sum - xrrot);
	bool pathright = hasPathBST(ptr->right, sum - xrrot);
	if (pathleft != false || pathright != false || sum - xrrot == 0)
	{
		isavailable = true;
	}


	return isavailable;
}


int main()
{
	node *root = NULL;
	root = createTree();
	int sum = 16;
	bool Isavailable = hasPathBST(root, sum);
	return 0;

}


