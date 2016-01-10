/*
author: Nitesh Thali
Given a BST, create a linked list of all the nodes at each depth.
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
void createLinkedLists(Node* root)
{
	queue <Node *> q;
	list <list <Node> > l;
	q.push(root);
	q.push(NULL);
	list < Node* > single;
	int i = 0;
	while(!q.empty())
	{
		Node * tmp = q.front();
		q.pop();
		if (tmp == NULL)	
		{
			l.push_back(single);
			single.clear();
			q.pop();
			if (!q.empty())
				q.push(NULL);
		}
		else
		{
			single.push_back(tmp);
			q.push(tmp->left);
			q.push(tmp->right);
		}
	}
	//int length = i;
	list <list < Node > > :: iterator it, it1;
	//list <lsit <Node *>> :: <iterator> it1;
	for (it = l.begin(); it != l.end(); ++it)
	{
		// for (it1 = (*it).begin(); it1 != (*it).end(); ++it1)
		// {
		// 	cout << (*it1)->data << "->";	
		// }
			cout << (*it);
			cout <<endl;
	}		
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
	inorder(root);
	createLinkedLists(root);
	cout <<endl;
}