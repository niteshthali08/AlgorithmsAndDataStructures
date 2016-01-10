/*
author: Nitesh Thali
TO check if tree is balanced or not.
*/
#include <iostream>
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
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	
}
int findMaxHeight(Node *root, int max_height)
{
	if(root == NULL)
	{
		return max_height;
	}
	int l = findMaxHeight(root->left, 1+max_height);
	int h = findMaxHeight(root->right, 1+max_height);
	if (l >= h)
		max_height = l;
	else
		max_height = h;
	//cout << "return max height: " << max_height << ", root: " << root->data<<endl;
	return max_height;
}

int findMinHeight(Node *root, int min_height)
{
	if(root == NULL)
	{
		return min_height;
	}
	int l = findMaxHeight(root->left, 1+min_height);
	int h = findMaxHeight(root->right, 1+min_height);
	if (l >= h)
		min_height = h;
	else
		min_height = l;
	//cout << "return min height: " << min_height << ", root: " << root->data<<endl;
	return min_height;
}

int main(int argc, char const *argv[])
{
	Node *root = getNode(50);
	root->left = getNode(10);
	root->right = getNode(100);
	root->left->left = getNode(5);
	root->left->right = getNode(20);
	root->right->left = getNode(60);
	root->right->left->left = getNode(55);
	root->right->left->left->left = getNode(52);
	int max = findMaxHeight(root, 0);
	int min = findMinHeight(root, 0); 
	inorder(root);
	cout <<endl;
	//cout << "Max Height: " << max <<endl;
	//cout << "Min Height: " << min <<endl;
	(max - min > 1) ? cout << "Tree is not balamced\n" : cout <<"Tree is Balanced\n";
	return 0;
}