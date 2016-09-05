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
void BFSKDistRoot(node *ptr1, int klevel)
 {
	if (ptr1 == NULL)
	{
		return ;
	}

	if (klevel == 0)
	{
		cout << ptr1->value;
	}
	
 BFSKDistRoot(ptr1->left, klevel -1);
 BFSKDistRoot(ptr1->right, klevel -1);
	

}


int main()
{
	node *root1 = NULL;
	root1 = createTree();
	BFSKDistRoot(root1,3);
	return 0;

}


