#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
void preorder(Node *root)
{
	if(root)
	{
		cout << root->data << " ";
		preorder(root->left);
		
		preorder(root->right);
	}
	
}
Node* getNode(int data)
{
	Node *tmp = new Node();
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}
Node* removePathNodes(Node *root, int &sum, int k)
{
	if (root == NULL)
		{
			cout << "Returning NULL " <<endl;
			return NULL;
		
		}
	int ls, rs;
	ls = rs = sum + root->data;
	cout << "calling left ls, rs " << ls << " " << rs << endl;
	root->left = removePathNodes(root->left, ls, k);
	cout << "Calling right ls, rs " << ls << " " << rs << endl;
	root->right = removePathNodes(root->right, rs, k);
	cout << " " << ls << " " <<rs <<endl;
	sum = (ls > rs) ? ls : rs;
	if (sum < k)
		{
			cout << "deleting node by returning NULL "<<endl;
		 	root = NULL;
		}
	return root;
}
int main(int argc, char const *argv[])
{
	Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->right->left = getNode(4);
	root->right->right = getNode(5);
	root->right->left->left = getNode(6);
	root->right->left->left->right = getNode(8);
	root->right->right->right = getNode(7);
	root->right->right->right->left = getNode(9);
	root->right->right->right->left->left = getNode(10);
	int k =100;
	int sum = 0;
	Node * tmp = removePathNodes(root, sum, k);
	if (sum < k)
		root = NULL;
	cout << "Preorder after deletion: "; preorder(root); cout <<endl;
	return 0;
}