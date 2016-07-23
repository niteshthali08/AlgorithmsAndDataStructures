//
//  main.cpp
//  Construct_Tree_from_preorder_and_NL_array
//
//  Created by Nitesh Thali on 7/22/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
 Question : http://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
 Construct a special tree from given preorder traversal (every node has no child or two children)
 Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
 Output: Root of following tree
    10
   /  \
 30   15
 /  \
 20   5
 
 Solution: Is to do normal preorder traversal and pre[] and return when corresponding node is L in preLN[]
 Other way of thinking this is if preNL == 'N', that means this is a internal node and will have two children
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
void preorder(Node *root)
{
    if(root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
}
Node* constructTree(int pre[], char preLN[], int len, int& index){
    if (index >= len )
        return NULL;
    if(preLN[index] == 'L'){
        Node * leaf = getNode(pre[index]);
        return leaf;
    }
    Node * root = getNode(pre[index]);
    index += 1;
    root->left = constructTree(pre, preLN, len, index);
    index += 1;
    root->right = constructTree(pre, preLN, len, index);
    return root;
    
}
int main(int argc, const char * argv[]) {
//    int pre[] = {10, 30, 20, 5, 15};
//    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int pre [] = {50, 10, 5, 20, 2, 100, 60, 55, 150};
    char preLN[] = {'N','N','L','N','L','N','N','L','L'};
    int len = sizeof(pre)/sizeof(int), index = 0;
    Node* root = constructTree(pre, preLN, len, index);
    cout << "Preorder traversal for constructed Tree: "; preorder(root);
    return 0;
}
