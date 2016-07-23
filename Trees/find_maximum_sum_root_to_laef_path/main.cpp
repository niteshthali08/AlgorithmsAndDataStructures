//
//  main.cpp
//  find_maximum_sum_root_to_laef_path
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Find maximum sun leaf to root path.
 Solution: Instead of storing whole path we can just store the location of leaf node. After that we can do one more traversal of tree to print the path.
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
void findMaxLeafNode(Node* root, int sum, int& maxSum, Node* &maxLeaf){
    if(root == NULL)
        return;
    if(!root->left && !root->right){
        sum += root->data; // this is important, dont forget to add leaf's value.
        if(sum > maxSum){
            maxSum = sum;
            maxLeaf = root;
        }
        return;
    }
    sum += root->data;
    findMaxLeafNode(root->left, sum, maxSum, maxLeaf);
    findMaxLeafNode(root->right, sum, maxSum, maxLeaf);
}
bool printPath(Node* root, Node* leaf){ // printing leaf to root path.
    if (root == NULL)
        return false;
    if (root == leaf){
        cout << root->data << " ";
        return true;
    }
    if(printPath(root->left, leaf)){
        cout << root->data << " ";
        return true;
    }
    if(printPath(root->right, leaf)){
        cout << root->data << " ";
        return true;
    }
    return false;
}
void findMaxSumPath(Node *root)
{
    Node* maxLeaf = NULL;
    int sum = 0, maxSum = INT_MIN;
    findMaxLeafNode(root, sum, maxSum, maxLeaf);
    printPath(root, maxLeaf);
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
     2   155
     
     */
    Node *root = getNode(50);
    root->left = getNode(10);
    root->right = getNode(100);
    root->left->left = getNode(5);
    root->left->right = getNode(20);
    root->left->left->right = getNode(2);
    root->right->left = getNode(60);
    root->right->right = getNode(150);
    root->right->left->left = getNode(155);
   
    findMaxSumPath(root);
    cout <<"\n";
    return 0;
}