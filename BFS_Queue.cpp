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
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	root->left->left->right = getNewNode(8);
	return root;
}


//assuming root lies in the given range
void PrintLevelBST(node *ptr)
{


	if (ptr == NULL)
		return ;

	queue<node *> q;
	q.push(ptr);


	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		node *qnode = q.front();
		cout << qnode->value << " ";
		q.pop();

		/* Enqueue left child */
		if (qnode->left != NULL)
			q.push(qnode->left);

		/*Enqueue right child */
		if (qnode->right != NULL)
			q.push(qnode->right);
	}


}


int main()
{
	node *root = NULL;
	root = createTree();
	PrintLevelBST(root);
	return 0;

}


