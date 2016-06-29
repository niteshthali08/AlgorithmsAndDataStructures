//
//  main.cpp
//  max_diff_between_nodes_ancesstors
//
//  Created by Nitesh Thali on 6/10/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
Maximum difference between node and its ancestor in Binary Tree
 Question reference from : http://www.geeksforgeeks.org/maximum-difference-between-node-and-its-ancestor-in-binary-tree/
    Return the maximum difference which can be obtained by subtracting ancesstor with node value at any level below the ancesstor.
    Time Complexity should be O(n)
    Solution: 
    1. Traverse bottom up fashion.
    2. At each internal node calculate difference betwen its value and child with min value. Store this difference and pass min node to the parent (min amongst node, its left and its right).
    3. Do this recursively.
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
Node* maxDiffHelper (Node* root, int &md)
{
    if (root == NULL || (root->left == NULL && root->right == NULL)){
        return root;
    }
    Node* left = maxDiffHelper(root->left, md);
    Node* right = maxDiffHelper(root->right, md);
    int lval = (left)? left->data : 99999;
    int rval = (right)? right->data : 99999;
    int min = rval;
    Node* minNode = right;
    if (lval < rval){
        min = lval;
        minNode = left;
    }
    (md < (root->data - min))? md = root->data - min : md;
    if (root->data < min)
        minNode = root;
    return minNode;
}
int getMaxDiff(Node* root)
{
    int maxDiff = -99999;
    if (root == NULL) return maxDiff;
    root = maxDiffHelper(root, maxDiff);
    return maxDiff;
}
int main(int argc, const char * argv[]) {
    /*
                8
               / \
              3   10
             / \    \
            1   6    14
                /\   /
               4  7 13
     
     */
    Node* root;
    root = getNode(8);
    root->left = getNode(3);
    
    root->left->left = getNode(1);
    root->left->right = getNode(6);
    root->left->right->left = getNode(4);
    root->left->right->right = getNode(7);
    
    root->right = getNode(10);
    root->right->right = getNode(14);
    root->right->right->left = getNode(13);
    inorder(root);
    cout << "\nMax difference is: " << getMaxDiff(root) << endl;
    return 0;
}
