//
//  main.cpp
//  Tree_Isomorphosm_Problem
//
//  Created by Nitesh Thali on 7/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 from: geeksforgeeks
 Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
 
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

bool isIsomorphic(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    
    if (root1 == NULL || root2 == NULL)
        return false;
    
    if (root1->data != root2->data)
        return false;
   // check for both the condition 1. Swapped 2. Not swapped.
    return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))||
            (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
      10  100
     / \   / \
     5 20 60 150
     
        50
       /  \
      10  100
     / \   / \
    20  5  150 60
     
    They have the same structure.
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
   
    root->right->left = getNode(60);
    root->right->right = getNode(150);
   
    
    Node *root2 = getNode(50);
    root2->left = getNode(10);
    root2->right = getNode(100);
    root2->left->left = getNode(20);
    root2->left->right = getNode(5);
    root2->right->left = getNode(150);
    root2->right->right = getNode(60);
   
   
    cout << "Is Isomorphoc ? : ";
    isIsomorphic(root, root2) == true ? cout << "True\n" : cout << "False\n";
    return 0;
}