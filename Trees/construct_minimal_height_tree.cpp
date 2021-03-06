/*
author: Nitesh Thali
Given s sorted array write an algorithm to create a biinary tree with minimal height.
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
Node* createMinimalHeightTree(int arr[], int l, int h)
{
	if ( l >	 h )
	{
		//cout << "l, h: " << l << " " << h <<endl;
		return NULL;
	}
	int mid = (l+h)/2;
	Node *root = getNode(arr[mid]);
	//cout << "left -- l, h: " << l << " " << h <<endl;
	root->left = createMinimalHeightTree(arr, l, mid-1);
	//cout << "right -- l, h: " << l << " " << h <<endl;
	root->right = createMinimalHeightTree(arr, mid+1, h);
	//cout << "returning root: " << root -> data << endl;
	return root;
	
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 30, 40, 50, 60, 80, 90, 100, 110};
	int n = sizeof(arr)/sizeof(int);
	Node *root = createMinimalHeightTree(arr, 0, n-1);
	inorder(root);
	cout << endl;
	return 0;
}