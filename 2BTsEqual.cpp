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
bool IsBTSEqual(node *ptr1, node *ptr2)
 {
	bool isavailable = false;
	if (ptr1 == NULL && ptr2 == NULL)
	{
		return true;
	}
	//false if change is present int he leaf node
	if (ptr1 == NULL || ptr2 == NULL)
	{
		return false;
	}
	
	bool pathleft= IsBTSEqual(ptr1->left, ptr2->left);
	bool pathright = IsBTSEqual(ptr1->right, ptr2->right);
	if (pathleft != false &&  pathright != false && ptr1->value == ptr2->value)
	{
		isavailable = true;
	}


	return isavailable;
}


int main()
{
	node *root1 = NULL;
	node *root2 = NULL;
	root1 = createTree();
	root2 = createTree();
	bool Isavailable = IsBTSEqual(root1, root2);
	return 0;

}


