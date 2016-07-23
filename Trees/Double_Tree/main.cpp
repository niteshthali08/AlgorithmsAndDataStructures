//
//  main.cpp
//  Double_Tree
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*

Double Tree Ref: http://www.geeksforgeeks.org/double-tree/
Write a program that converts a given tree to its Double tree. To create Double tree of the given tree, create a new duplicate for each node, and insert the duplicate as the left child of the original node.
 
     2
    / \
    1   3
 is changed to…
 
      2
     / \
    2   3
    /  /
    1  3
   /
   1

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
Node* getDoubleTree(Node* root){
    if(root == NULL)
        return NULL;
    
    root->left = getDoubleTree(root->left);
    root->right = getDoubleTree(root->right);
    
    Node* dup_node = getNode(root->data);
    Node* old_left = root->left;
    root->left = dup_node;
    dup_node->left = old_left;

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
     \  /
     2 55
     
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
    cout << "Inorder for Original tree: "; inorder(root); cout << "\n";
     root = getDoubleTree(root);
    cout << "Inorder for Double tree: "; inorder(root); cout << "\n";
    return 0;
}