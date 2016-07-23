//
//  main.cpp
//  Convert_BTree_to_hold_Children_Sum_Property.
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Ref: http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
    Convert an arbitrary Binary Tree to a tree that holds Children Sum Property.
    Question: Given an arbitrary binary tree, convert it to a binary tree that holds Children Sum Property. You can only increment data values in any node (You cannot change structure of tree and cannot decrement value of any node).
      50
    /    \
   /      \
  7        2
 / \       /\
/   \     /  \
3    5   1   30
 
 OUTPUT:
      50
    /   \
   /     \
 19        31
 / \      /  \
/   \    /    \
14   5  1     30
 
 Soution: Is to do post order traversal and increment the respective nodes. But when we set the property for below nodes but at later stage change its parent then we will have to again run same algo on its children. Please see below code for the same.

 Time Complexity: O(n^2)
 
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
void getSumTree(Node* root)
{
    if(!root) return;
    if(!root->left && !root->right)
        return;
    getSumTree(root->left);
    getSumTree(root->right);
   	
    int data = root->data, left, right;
    if(root->left)
        left = root->left->data;
    if(root->right)
        right = root->right->data;
    if(data == left+right) // tree is already sum tree
        return;
    else if(data < left + right) // increment roots data.
    {
        root->data = left + right ;
        return;
    }
    else // roots data is greater than sum of its left and right child. Increament children.
    {
        if(root->left)
        {
            root->left->data += data - (left + right);
            getSumTree(root->left); // special case, need to rectify left and its children as well.
        }
        else{
            root->right->data += data - (left + right);
            getSumTree(root->right); // special case
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
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
   
    root->right->left = getNode(60);
    root->right->right = getNode(150);
   
    cout << "Inorder of original tree: "; inorder(root); cout << "\n";
    getSumTree(root);
    cout << "Inorder of Sum tree: "; inorder(root); cout << "\n";
    
    
    Node *root2 = getNode(50);
    root2->left        = getNode(7);
    root2->right       = getNode(2);
    root2->left->left  = getNode(3);
    root2->left->right = getNode(5);
    root2->right->left  = getNode(1);
    root2->right->right = getNode(30);
    
    cout << "Inorder of original tree: "; inorder(root2); cout << "\n";
    getSumTree(root2);
    cout << "Inorder of Sum tree: "; inorder(root2); cout << "\n";

    
    return 0;
}
