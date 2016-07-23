//
//  main.cpp
//  Populate_Inorder_Successor_for_all_nodes
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
   http://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
   Populate Inorder Successor for all nodes
   Given a Binary Tree where each node has following structure, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
 
 struct node
 {
 int data;
 struct node* left;
 struct node* right;
 struct node* next;
 }
 
 Solution: Simple inorder traversal we can do this.
 */

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right, *next;
};

Node* getNode(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->left = tmp->right = tmp->next = NULL;
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
void inorder_next(Node* root){
    while (root) {
        cout << root->data << " ";
        root = root->next;
    }
}
void populateNextPointer(Node* root, Node* &prev){
    if (root == NULL)
        return;
    
    if(root->left == NULL && prev == NULL){ // set it for the first time.
        prev = root;
    }
    
    populateNextPointer(root->left, prev);
    if(prev){
        prev->next = root;
        prev = root;
    }
    populateNextPointer(root->right, prev);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
     10   100
     / \   / \
     5 20 60 150
     \    /
     2   55
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->right = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    Node *prev = NULL;
    populateNextPointer(root, prev);
    cout <<"Inorder traversal using left and right pointers: \n"; inorder(root); cout << "\n";
    cout <<"Inorder traversal using next pointer: \n"; inorder_next(root->left->left); cout << "\n";

    return 0;
}

