/*
author: Nitesh Thali
Determin the size of the longest BST subtree in a given tree.
@author: Nitesh Thali
*/
#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node* getNode(int data)
{
	Node *tmp = new Node();
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}
int minimum(int a, int b)
{
	if (a<b)
		return a;
	return b;
}
int maximum(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	
}
int find_largest_BST(Node *root, int &min, int &max, bool &isBST, int &maxSize)
{
	min = 99999, max = -99999;
	if (root == NULL)
	{
		isBST = true;
		//cout << "node: " << root->data << " min: " <<min << " max: " << max << " isBST " << isBST << " size: " << maxSize << endl;
		return 0;
	}
	
	//cout << "calling node with data : " <<root->data <<endl;
	int leftSize = find_largest_BST(root->left, min, max, isBST, maxSize);
	bool isLeftValid = (max < root->data) && (isBST); 
	int tempMin =  minimum(root->data, min);
	int tempMax = maximum (root->data, max);

	

	//cout << "isLeftValid: " <<isLeftValid <<": " << tempMax << endl;

	int rightSize = find_largest_BST(root->right, min, max, isBST, maxSize);
	//cout << "Now root: " << root->data << ", " << min << " "<< max <<endl;
	bool isRightValid = (root->data < min) && (isBST);
	//cout << "isRightValid: " <<isRightValid << " : " << min <<endl;
	
	min = minimum(tempMin, min);
	max = maximum(tempMax, max);

	if (isLeftValid && isRightValid)
	{
		isBST = true;
		if ((1 + leftSize + rightSize) > maxSize) // both are valid so size is 1+ left+righ subtree size.
			maxSize = 1 + leftSize + rightSize;
		//cout << "returning max size: " <<maxSize <<endl;
		cout << "node: " << root->data << " min: " <<min << " max: " << max << " isBST " << isBST << " size: " << maxSize << endl;
		return 1+ leftSize + rightSize;
	}
	isBST = false;
	cout << "node: " << root->data << " min: " <<min << " max: " << max << " isBST " << isBST << " size: " << maxSize << endl;
	cout << "returning -1" <<endl;
	return -1;

}

int main(int argc, char const *argv[])
{
	
	// Node *root = getNode(50);
	// root->left = getNode(10);
	// root->right = getNode(100);
	// root->left->left = getNode(5);
	// root->left->left->right = getNode(123);
	// root->left->left->left = getNode(500);
	// root->left->right = getNode(20);
	// root->left->right->right = getNode(200);
	// root->right->left = getNode(60);
	// root->right->left->left = getNode(55);
	// root->right->left->left->left = getNode(52);
	// Node *p = root->left->left->left;
	// Node *q = root->left->left->right; 

	// Node *root = getNode(10);
	// root->left = getNode(6);
	// root->right = getNode(12);
	// root->left->left = getNode(7);
	// root->left->right = getNode(4);
	// root->right->left = getNode(9);
	// root->right->right = getNode(14);
	// root->right->right->left = getNode(13);
	// root->right->right->right = getNode(16);

	Node *root = getNode(50);
	root->left = getNode(10);
	root->right = getNode(100);
	root->left->left = getNode(5);
	root->left->right = getNode(15);
	root->right->left = getNode(70);
	root->right->right = getNode(150);

	int min = 99999, max = -99999, maxSize = 0;	
	bool isBST = false;
	cout << "Inorder traversal of Tree: "; inorder(root); cout<< endl;
	find_largest_BST(root, min, max, isBST, maxSize);
	cout << "Max size BST: " << maxSize;
	
	cout <<endl;
}