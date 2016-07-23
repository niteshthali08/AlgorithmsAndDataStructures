//
//  main.cpp
//  Print_nodes_that_dont_have_sibling
//
//  Created by Nitesh Thali on 7/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Print nodes that dont have a sibling.
 
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
void printNodesWithoutSibling(Node* root){
    // just do preorder traversal.
    if(root == NULL)
        return;
    if (root->left && !root->right)
        cout << root->left->data << " ";
    if(root->right && !root->left)
        cout << root->right->data << " ";
    
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    
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
    printNodesWithoutSibling(root);
    cout << endl;
    
    /************Test2***************/
    root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->right = getNode(4);
    root->right->left = getNode(5);
    root->right->left->left = getNode(6);
    printNodesWithoutSibling(root);
    cout << endl;
    
    return 0;
}