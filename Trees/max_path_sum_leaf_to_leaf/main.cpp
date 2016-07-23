//
//  main.cpp
//  max_path_sum_leaf_to_leaf
//
//  Created by Nitesh Thali on 7/20/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Find the maximum path sum between two leaves of a binary tree.
    O(n): Idea is to do post order traversal, keeping track of max_sum and the largest leaf to current node sum seen so far.
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
int leafToLeafMaxSum(Node *root, int & maxSum){
    int currSum = 0;
    if (root == NULL){
        return INT_MIN; // to handle the case when one side of subtree is empty.
    }
    if(root->left == NULL && root->right == NULL)// found a leaf
        return root->data;
    int left = leafToLeafMaxSum(root->left, maxSum);
    int right = leafToLeafMaxSum(root->right, maxSum);
   maxSum  = max(maxSum, root->data + left + right);
    currSum = root->data + max(left, right);
    return currSum;
    
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
    root->left->left->left = getNode(85);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(55);
    int maxSum = INT_MIN;
    leafToLeafMaxSum(root, maxSum);
    cout << "Maximum path sum between two leaves: " << maxSum << endl;
    return 0;
}



