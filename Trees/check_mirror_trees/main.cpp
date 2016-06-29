//
//  main.cpp
//  BinarySearchTree
//
//  Created by Nitesh Thali on 6/1/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//  Description: Starter code for creating a BST as drawn below. This code will be used by other program to qucikly generate a BST for testing their program.
/*
 Ref: http://www.geeksforgeeks.org/check-if-two-trees-are-mirror/
 Program to check if given two trees are mirror images of each other.
 For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true:
    1. Their root node’s key must be same
    2. Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
    3. Right subtree of ‘a’ and left subtree of ‘b’ are mirror.

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

bool checkMirror(Node* t1, Node* t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if(t1 == NULL || t2 == NULL)
        return false;
    if (t1->data != t2->data)
        return false;
    return checkMirror(t1->left, t2->right) && checkMirror(t1->right , t2->left);
    /*
     another compact way:
     return t1->data == t2->data && checkMirror(t1->left, t2->right) && checkMirror(t1->right , t2->left);
     */
}
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /*
        50                      
        /  \
     10     100
     / \    /  \
     5 20  60  150
     
         50
        /  \
     100     10
     / \     / \
     150 60  20  5

     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    
    Node *root2 = getNode(50);
    root2->left = getNode(100);
    root2->right = getNode(10);
    root2->left->left = getNode(150);
    root2->left->right = getNode(60);
    root2->right->left = getNode(20);
    root2->right->right = getNode(5);
    cout << "Tree1: ";
    inorder(root);
    cout << "\nTree2: ";
    inorder(root2);
    cout << "\n";
    //root2 = NULL;
    cout << "Tree1 and Tree2 are mirror images? " << checkMirror(root, root2) << endl;
    return 0;
}
/*
 Note: Inorder for Mirror trees are reverese of each other
 root: 5 10 20 50 60 100 150
 root2: 150 100 60 50 20 10 5
 
 Another method: could be to get inorder for both, reverse any one of them and check for equality, but that's expensive
 */
