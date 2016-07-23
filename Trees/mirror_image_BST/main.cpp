//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to construct a mirror image of the given binary tree.
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

void mirrorImageBST(Node* root)
{
    if (root == NULL)
        return;
    mirrorImageBST(root->left);
    mirrorImageBST(root->right);
    
    Node* t = root->left;
    root->left = root->right;
    root->right = t;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /*
        50
        /  \
     10     100
     / \    /  \
     5 20  60  150
    /       /
    2       55
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
    cout << "Tree: ";
    inorder(root);
    mirrorImageBST(root);
    cout << "\nMirror Image: ";
    inorder(root);
    return 0;
}
