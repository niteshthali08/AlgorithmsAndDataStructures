//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//  To delete the nodes having a single child from the tree.
/*
    Program to delete nodes containing a single child.
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

Node* deleteSingleNodes(Node* root){
    
    if (root == NULL)
        return root;
    /* Note: Tree will be changes hence post-order and left and right assignments*/
    root->left = deleteSingleNodes(root->left);
    root->right = deleteSingleNodes(root->right);
    
    if(root->left == NULL && root->right == NULL)
        return root;
    
    if (root->left == NULL){
        Node * p = root->right;
        delete root;
        return p;
    }
    if (root->right == NULL){
        Node * p = root->left;
        delete root;
        return p;
    }
    return root;
        
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
     10   100
     / \   / \
     5 20 60 150
     /     /   \
     2    55    200
            \
            58
            / \
           57  59
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->right->right = getNode(200);

    root->right->left->left = getNode(55);
    root->right->left->left->right = getNode(58);
    root->right->left->left->right->left = getNode(57);
    root->right->left->left->right->right = getNode(59);
    cout << "Inorder: "; inorder(root); cout << "\n";
    root = deleteSingleNodes(root);
    cout << "Inorder after deletion: "; inorder(root); cout << "\n";
    return 0;
}
