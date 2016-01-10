/*
author: Nitesh Thali
Given a Binary tree and two nodes find first common ancesstor of two nodes.
If BST, it is easy we just have to search for both the nodes and return the nodes where both path diverge.
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
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	
}

bool locate(Node *root, Node *p)
{
	if (root == NULL)
		return false;
	if (root == p)
		return true;
	bool l = locate(root->left, p);
	bool r = locate(root->right, p);
	return l || r; // Note or
}
Node* find_common_ancesstor(Node* root, Node *p, Node *q)
{
	//check if both node lie on right subtree or lef subtree .. while doing so find the first node where they differ and retun its parent	
	if (locate(root->left, p) && locate(root->left, q))
		{
			//cout << "calling left: " <<root->left->data <<endl;
			return find_common_ancesstor(root->left, p, q); // Important to have return here. this just returns result of the prev return
		}
	if(locate(root->right, p) && locate (root->right, q))
		{
			//cout << "calling right: " <<root->right->data <<endl;	
			return find_common_ancesstor(root->right, p, q);
		}
	//cout << "returning root: " << root->data << endl;
	return root;
}

int main(int argc, char const *argv[])
{
	Node *root = getNode(50);
	root->left = getNode(10);
	root->right = getNode(100);
	root->left->left = getNode(5);
	root->left->left->right = getNode(123);
	root->left->left->left = getNode(500);
	root->left->right = getNode(20);
	root->left->right->right = getNode(200);
	root->right->left = getNode(60);
	root->right->left->left = getNode(55);
	root->right->left->left->left = getNode(52);
	Node *p = root->left->left->left;
	Node *q = root->left->left->right;
	Node *node = find_common_ancesstor(root, p, q);
	cout <<"First common ancestor is " << node->data;
	cout <<endl;
}