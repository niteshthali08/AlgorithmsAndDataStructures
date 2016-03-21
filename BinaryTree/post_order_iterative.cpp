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
		printRecursivePostorder(root->left);
		printRecursivePostorder(root->right);
		cout << root->data<< " " ;
	}
}

void printIterativePostorder(node* root){
	stack<node *> s;
	node * last_pop = NULL;
	if(root == NULL) return;
	bool left_visited = false;
	s.push(root);
	while(!s.empty()){
		if (root->left != NULL && last_pop != root->left && last_pop != root->right){
			s.push(root->left);
			root = root->left;

		}
		else if (root->right != NULL && last_pop != root->right){
			s.push(root->right);
			root = root->right;
		}
		else{
			last_pop = s.top();
			s.pop();
			cout << last_pop->data << " "; 
			if(!s.empty())
				root = s.top();
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
	// 30, 35, 40, 70, 60 50
	cout << "Recursive postorder: ";
	printRecursivePostorder(root);
	cout << endl;
	cout << "Itereative postorder: ";
	printIterativePostorder(root);
	cout << endl;
	return 0;
}