//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//  Program to traverse tree in postorder fashion using recursive and iterative fucntion

#include <iostream>
#include <stack>
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
void postorder(Node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
        
    }
    
}
void postorder_iterative(Node* root)
{
    stack <Node*> st;
    Node* last_poped = root; // Important, if this is initialized to NULL, then algo will fail to push last leftmost tree ele.
    /*
     Important, here we have to take care to avoid putting same nodes again onto the stack. When we are printing root we check before pushing left and right if they were visited previously.
        Solution using two stacks
     1. Push root to first stack.
     2. Loop while first stack is not empty
     2.1 Pop a node from first stack and push it to second stack
     2.2 Push left and right children of the popped node to first stack
     3. Print contents of second stack
     */
        if(root == NULL) return;
        st.push(root);
        while(!st.empty()){
            if (root->left != NULL && last_poped != root->left && last_poped != root->right){
                st.push(root->left); // important push root->left
                root = root->left;
                
            }
            else if (root->right != NULL && last_poped != root->right){
                st.push(root->right);
                root = root->right;
            }
            else{
                last_poped = st.top();
                st.pop();
                cout << last_poped->data << " ";
                if(!st.empty())
                    root = st.top();
            }
        }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        50
       /  \
     10   100
     / \   / \
     5 20 60 150
     /     /
     2    55
          /
         52
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    root->right->left->left->left = getNode(52);
    cout << "Recursive Preorder: "; postorder(root); cout << "\n";
    cout << "Iterative Preorder: "; postorder_iterative(root);
    return 0;
}
