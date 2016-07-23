//
//  main.cpp
//  Boundary_Traversal_of_binary_tree
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Boundary traversal of a Binary Tree in anticlockwise fashion.*** (check implementation)
    This can do done in following way.
    1. print all nodes on left boundary.
    2. print all leaf nodes.
    3. print all nodes on right boundary.
 Care should be taken not to print corner nodes twice.
 
 
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
void printLefBoundary(Node* root){
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        return;
    
    if(root->left){
        cout << root->data << " ";
        printLefBoundary(root->left);
    }else{
        cout << root->data << " ";
        printLefBoundary(root->right);
    }
}
void printLeafNodes(Node* root){
    if (root == NULL)
        return;
    if (!root->left && !root->right){
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}
void printRightBoundary(Node *root){
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        return;
    if(root->right){
        printRightBoundary(root->right);
       
    }else{
        printRightBoundary(root->left);
    }
     cout << root->data << " ";
}
void printBoundary(Node* root){
    cout << root->data << " ";
    printLefBoundary(root->left);
    printLeafNodes(root);
    printRightBoundary(root->right);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
     10   100
     / \   / \
     5 20 60 150
     \   /    /
      2  55  15
             /
             21
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->right = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->right->left = getNode(15);
    root->right->right->left->left = getNode(21);
    root->right->left->left = getNode(55);
    printBoundary(root);
    return 0;
}