//
//  main.cpp
//  Sum_of_all_root_to_leaf_paths
//
//  Created by Nitesh Thali on 7/21/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to display sum of all paths from root to leaf.
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
void getTotalSum(Node* root, int& totalSum, int sum){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        sum += root->data;
        totalSum += sum;
        return;
    }
    sum += root->data;
    getTotalSum(root->left, totalSum, sum);
    getTotalSum(root->right, totalSum, sum);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /*
       50
      /  \
     10   100
     / \   / \
     5 20 60 150
        \    /
        2   55
     
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
    int totalSum = 0, sum = 0;
    getTotalSum(root, totalSum, sum);
    cout <<"Sum of all root to leaf paths: " << totalSum << endl;
    return 0;
}