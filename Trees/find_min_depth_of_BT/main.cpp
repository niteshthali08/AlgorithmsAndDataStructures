//
//  main.cpp
//  find_min_depth_of_BT
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
//
/*
    Program to find min depth of a binary tree.
    Path must end on a leaf
      50
      /
    10
    Above trees min depth is 2 and not 1
 */

#include <iostream>
#include <cmath>
#include <algorithm>
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
int findMinDepth(Node* root){
    /*
     //This program works correctly but it does not end on a leaf. Hence it returns wrong value.
     if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return 1 + min(findMinDepth(root->left), findMinDepth(root->right));
         50
         /
        10
     */
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int left_min = INT_MAX, right_min = INT_MAX;
    if (root->left)
        left_min = findMinDepth(root->left);
    if(root->right)
        right_min = findMinDepth(root->right);
    return 1 + min(left_min, right_min);
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        50
       /  \
      10   100
     / \   / \
     5 20 60 150
     /    /
    2    70
   /
  52
     */
    
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->left->left->left->left = getNode(52);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(70);
   
    cout << "Minimum depth of the given tree: " << findMinDepth(root)<< endl;
    return 0;
}