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

void printRecursiveInorder(node *root){
	if(root){
		printRecursiveInorder(root->left);
		cout << root->data<< " " ;
		printRecursiveInorder(root->right);
		
	}
}

void printIterativeInorder(node* root){
	stack<node *> s;
	node * last_pop = NULL;
	if(root == NULL) return;
	while(true){
		if(root){
			s.push(root);
			root = root->left;
		}
		else{
			if (s.empty()) break;
			last_pop = s.top();
			s.pop();
			cout << last_pop->data << " ";
			root = last_pop->right;
		}
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
	printRecursiveInorder(root);
	cout << endl;
	cout << "Itereative preorder: ";
	printIterativeInorder(root);
	cout << endl;
	return 0;
}