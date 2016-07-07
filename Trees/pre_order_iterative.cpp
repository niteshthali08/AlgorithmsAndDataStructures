#include <iostream>
#include <stack>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
node* getNode(int data){
	node * t = new node();
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void printRecursivePostorder(node *root){
	if(root){
		cout << root->data<< " " ;
		printRecursivePostorder(root->left);
		printRecursivePostorder(root->right);
		
	}
}

void printIterativePostorder(node* root){
	stack<node *> s;
	node * last_pop = NULL;
	if(root == NULL) return;
	bool left_visited = false;
	s.push(root);
	while(!s.empty()){
		cout << s.top()->data << " ";
		root = s.top();
		s.pop();
		if(root->right)
				s.push(root->right);
		if(root->left)
				s.push(root->left);	
	}
}

int main(int argc, char const *argv[]){
	
	node *root = getNode(50);
	root->left = getNode(40);
	root->right  = getNode(60);
	root->left->left = getNode(30);
	root->left->right = getNode(35);
	root->right->right = getNode(70);
	// 50, 40, 30, 35, 60, 70
	cout << "Recursive  preorder: ";
	printRecursivePostorder(root);
	cout << endl;
	cout << "Itereative preorder: ";
	printIterativePostorder(root);
	cout << endl;
	return 0;
}