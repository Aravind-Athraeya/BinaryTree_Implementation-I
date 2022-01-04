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
// create the tree
node *createTree() {
	node *root = getNewNode(20);
	root->left = getNewNode(8);
	root->right = getNewNode(22);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(12);
	return root;
}

void printBST(node *ptr, int var1, int var2)
{
	

if (ptr == NULL)
		return;
	
 
 printBST(ptr->left, var1, var2);
 if(ptr->value >= var1 && ptr->value >= var2)
 cout << ptr->value;
 printBST(ptr->right, var1, var2);




}

// Easy
int main()
{
	node *root = NULL;
	root = createTree();
	int var1 = 10, var2 = 22;
	printBST(root,var1, var2);
	return 0;
	
}


