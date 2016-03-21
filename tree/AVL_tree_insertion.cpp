#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;
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
	tmp->height = 1; //by default heght is 1.
	tmp->left = tmp->right = NULL;
	return tmp;
}
int getMax(int a, int b)
{
	return (a>b) ? a : b;
}
int getHeight(Node* node)
{ 
	if (node == NULL) // function is required to return 0 if node is null.
		return 0;
	return node->height;
}	
int getHeightDifference(Node* node)
{
	if (node == NULL)
		return 0;
	else return (getHeight(node->left) - getHeight(node->right));
}
Node* rightRotate(Node * node)
{
	Node *beta = node->left;
	Node *betaRight = beta->right;

	beta->right = node;
	node->left = betaRight;

	//update the heights
	beta->height = 1 + max(getHeight(beta->left), getHeight(beta->right));
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	return beta;
}
Node* leftRotate(Node * node)
{
	Node *beta = node->right;
	Node *betaLeft = beta->left;

	beta->left = node;
	node->right = betaLeft;

	//update the heights
	beta->height = 1 + max(getHeight(beta->left), getHeight(beta->right));
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	return beta;
}
Node* insert(Node *root, int key)
{
	if (root == NULL)
	{
		return getNode(key);
	}
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root ->right = insert(root->right, key);

	root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
	int balance = getHeightDifference(root);
	
	//4 cases:  balance > 1 -> left cases
	if (balance > 1 && root->left->data > key) // left left -> do right rotation on root;
		return rightRotate(root);
	if(balance > 1 && key >root->left->data ) // left right case, two rotations.
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}	
	// balance < -1, -> right cases	
	if (balance < -1 && key > root->right->data)// right right case, perform left rotation	
		return leftRotate(root);
	if (balance < -1 && root->right->data > key ) // right left case, 2 rotations
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
int main(int argc, char const *argv[])
{
	Node *root = NULL;
	root = insert(root, 0);
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 5);

	// root = insert(root, 6);
	// root = insert(root, 5);
	// root = insert(root, 4);


	// root = insert(root, 1);
	// root = insert(root, 2);
	// root = insert(root, 3);
	
	

	preorder(root);
	cout <<endl;
	return 0;
}