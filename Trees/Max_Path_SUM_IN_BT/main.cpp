//
//  main.cpp
//  Max_Path_SUM_IN_BT
//
//  Created by Nitesh Thali on 7/18/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 QUESTION: http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
 Maximum Path Sum in a Binary Tree
 Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
 
        1
        /\
       2  3
    output: 6
 
    Tree can contain negative values as well.
 
    Idea: is to do post order traversal and propagate sum upwards only if it is greater than 0 otherwise propogate 0.
 
 */

#include <iostream>
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

int getMaxPathSum(Node* root, int& maxSum){
    if(root == NULL)
        return 0;
    int left = getMaxPathSum(root->left, maxSum);
    int right = getMaxPathSum(root->right, maxSum);
    int sum = left + right + root->data;
    if (sum > maxSum)
        maxSum = sum;
    
    return max(root->data + max(left, right), root->data); // this is important
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
        50
       /  \
      -10   100
     / \   / \
     5 20 60 150
     /     /
     2    -155
            /
          -52
     */
    Node *root = getNode(50);
    root->left = getNode(-10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->left = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(-155);
    root->right->left->left->left = getNode(-52);
    int maxSum = INT_MIN;
    getMaxPathSum(root, maxSum);
    cout << "Max path sum: " << maxSum << endl;
    return 0;
}